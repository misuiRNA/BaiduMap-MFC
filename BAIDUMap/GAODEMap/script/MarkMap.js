var map = new BMap.Map("allmap");
var s = 108.953528;
var e = 34.267551;
var pointGloble = new BMap.Point(s, e);

map.centerAndZoom(pointGloble, 5);
map.enableScrollWheelZoom(true);

var size = new BMap.Size(10, 20);
map.addControl(new BMap.CityListControl({
    anchor: BMAP_ANCHOR_TOP_LEFT,
    offset: size
}));

//为动态页面加载所提供的方法
function mainMap() {
    var point = new BMap.Point(108.953528, 34.267551);
    map.centerAndZoom(point, 5);
    map.clearOverlays();
    map.enableScrollWheelZoom(true);
}

function showMap(s, e) {
    map.clearOverlays();
    var point = new BMap.Point(s, e);
    map.centerAndZoom(point, 18);
    var marker = new BMap.Marker(point);
    map.addOverlay(marker);
    marker.setAnimation(BMAP_ANIMATION_BOUNCE);
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
    map.clearOverlays();
    map.setCenter(pointsArray[0]);
    for (i = 0; i < pointsArray.length; i++) {
        var m = new BMap.Marker(pointsArray[i]);
        map.addOverlay(m);
        m.setAnimation(BMAP_ANIMATION_BOUNCE);
    }
}

//在地图中显示折线
var polyline = new BMap.Polyline([], { strokeColor: "blue", strokeWeight: 3, strokeOpacity: 0.5 });
function pinPolyline(pointsStr) {
    var pointsArray = stringToPiontArray(pointsStr);
    if (pointsArray == null || pointsArray.length == 0) return;
    map.setCenter(pointsArray[0]);
    map.removeOverlay(polyline);
    polyline.setPath(pointsArray);
    map.addOverlay(polyline);
}

//地图中显示封闭多边形
var polygon = new BMap.Polygon([], { strokeColor: "green", fillColor: "green", strokeWeight: 1.0, strokeOpacity: 0.3, fillOpacity: 0.3 });
function pinPolygon(pointsStr) {
    var pointsArray = stringToPiontArray(pointsStr);
    if (pointsArray == null || pointsArray.length == 0) return;
    map.setCenter(pointsArray[0]);
    map.removeOverlay(polygon);
    polygon.setPath(pointsArray);
    map.addOverlay(polygon);
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
    showPointValueInHtml(c);
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
