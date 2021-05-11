var map = new BMap.Map("allmap");
var s = 108.953528;//用来接收经度的参数
var e = 34.267551;//用来接收纬度的参数
var pointGloble = new BMap.Point(s, e);//新建一个位置对象，用于设置地图中心和覆盖物位置
//为保证页面在加载时可以直接显示地图，以下两句必不可少
map.centerAndZoom(pointGloble, 5);
map.enableScrollWheelZoom(true);

//map.enableInertialDragging();
//map.enableContinuousZoom();
var size = new BMap.Size(10, 20);
map.addControl(new BMap.CityListControl({
    anchor: BMAP_ANCHOR_TOP_LEFT,
    offset: size
}));

//为动态页面加载所提供的方法
function mainMap() {   //显示一张以西安市钟楼为中心的地图，由C#调用
    var point = new BMap.Point(108.953528, 34.267551);
    map.centerAndZoom(point, 5);
    map.clearOverlays();   //清除地图上的覆盖物
    map.enableScrollWheelZoom(true);
}

function showMap(s, e) {
    map.clearOverlays();   //清除地图上的覆盖物
    var point = new BMap.Point(s, e);
    map.centerAndZoom(point, 18);
    var marker = new BMap.Marker(point);  // 创建标注
    map.addOverlay(marker);               // 将标注添加到地图中
    marker.setAnimation(BMAP_ANIMATION_BOUNCE); //跳动的动画
}

function getCenterPoint() {
    var point = map.getCenter();
    var lng = point.lng;
    var lat = point.lat;
    return lng + "," + lat;
}

//在地图上显示坐标点群，该方法供C++调用
function pinpoints(pointsStr) {
    var pointsArray = stringToPiontArray(pointsStr);
    if (pointsArray == null || pointsArray.length == 0) return;
    map.clearOverlays();   //清除地图上的覆盖物
    map.setCenter(pointsArray[0]);
    for (i = 0; i < pointsArray.length; i++) {
        var m = new BMap.Marker(pointsArray[i]);
        map.addOverlay(m);
        m.setAnimation(BMAP_ANIMATION_BOUNCE); //跳动的动画
    }
}

//在地图中显示折线
var polyline = new BMap.Polyline([], { strokeColor: "blue", strokeWeight: 3, strokeOpacity: 0.5 });     //构造折线对象
function pinPolyline(pointsStr) {
    var pointsArray = stringToPiontArray(pointsStr);
    if (pointsArray == null || pointsArray.length == 0) return;
    map.setCenter(pointsArray[0]);
    map.removeOverlay(polyline);                //清除原有折线
    polyline.setPath(pointsArray);
    map.addOverlay(polyline);                   //添加新折线
}
//地图中显示封闭多边形
var polygon = new BMap.Polygon([], { strokeColor: "green", fillColor: "green", strokeWeight: 1.0, strokeOpacity: 0.3, fillOpacity: 0.3 });
function pinPolygon(pointsStr) {
    var pointsArray = stringToPiontArray(pointsStr);
    if (pointsArray == null || pointsArray.length == 0) return;
    map.setCenter(pointsArray[0]);
    map.removeOverlay(polygon);                //清除原有折线
    polygon.setPath(pointsArray);
    map.addOverlay(polygon);                   //添加新折线
}

//将包含多组点信息的字符串解析为BMap.Point的数组
function stringToPiontArray(str) {
    var pointArray = new Array();
    var strs = str.split(";");
    for (i = 0; i < strs.length; i++) {
        var p = strs[i].split(",");
        pointArray.push(new BMap.Point(p[0], p[1]));
    }
    return pointArray;
}

//传入C++对象，供JS调用C++代码
var cpp_object;
function SaveCppObject(obj) {
    cpp_object = obj;
}
//地图中右击鼠标，获取对应坐标
map.addEventListener("rightclick", function (c) {
    showPointValueInHtml(c);//在地图上使用便签显示经纬度值
    //在该方法体内处理获得的经纬度数据（传到C++或者其他途径显示），直接使用c.point即可获得当前点坐标
    cpp_object.ShowPointString(c.point.lng + "," + c.point.lat);
});
function returnMousePoint() {
    return mousePoint;
}
var temp = {
    pt: [],
    mk: [],
    iw: [],
    iwOpenIndex: null,
    mouseLabel: null,
    poiSearchMark: null,
    geoCoder: null
};
function showPointValueInHtml(c) {
    if (!temp.mouseLabel) {
        createMouseMoveLabel(c.point)
    }
    if (!temp.mouseLabel.isVisible()) {
        temp.mouseLabel.show()
    }
    var k = temp.mouseLabel;
    var h = map.getContainer();
    var g = h.clientWidth;
    var f = h.clientHeight;
    var j = 132;
    var i = 19;
    var n = map.pointToPixel(c.point).x + 13;
    var l = map.pointToPixel(c.point).y + 20;
    var m = map.pixelToPoint(new BMap.Pixel(g - j - 13, f - i - 20));
    var b = map.pixelToPoint(new BMap.Pixel(n - j - 33, f - i - 20));
    var d = c.point;
    if (g - n < j) {
        d = new BMap.Point(m.lng, d.lat)
    }
    if (f - l < i) {
        d = new BMap.Point(d.lng, m.lat)
    }
    if (g - n - 16 < j && f - l < i) {
        d = b
    }
    k.setPosition(d);
    k.setContent(c.point.lng + "," + c.point.lat)
}
function createMouseMoveLabel(c) {
    var a = map.pixelToPoint(new BMap.Pixel(0, 0));
    var b = c.lng + "," + c.lat;
    var d = new BMap.Label(b, {
        point: a,
        offset: new BMap.Size(13, 20),
        enableMassClear: false
    });
    d.setStyle({
        background: "#fff",
        border: "#999 solid 1px",
        zIndex: 10000000
    });
    map.addOverlay(d);
    temp.mouseLabel = d
}