
var map = new BMap.Map("allmap");
mainMap();

map.addControl(new BMap.CityListControl({
    anchor: BMAP_ANCHOR_TOP_LEFT,
    offset: new BMap.Size(10, 20)
}));

function mainMap() {
    var point = new BMap.Point(108.953528, 34.267551);
    map.centerAndZoom(point, 5);
    map.clearOverlays();
    map.enableScrollWheelZoom(true);
}

function showMap(lng, lat) {
    map.clearOverlays();
    var point = new BMap.Point(lng, lat);
    map.centerAndZoom(point, 18);
    var marker = new BMap.Marker(point);
    map.addOverlay(marker);
    marker.setAnimation(BMAP_ANIMATION_BOUNCE);
}

function getCenterPoint() {
    var point = map.getCenter();
    return point.lng + "," + point.lat;
}

function showPoints(pointsStr) {
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

function showPolyline(pointsStr) {
    var polyline = new BMap.Polyline([], { strokeColor: "blue", strokeWeight: 3, strokeOpacity: 0.5 });
    var pointsArray = stringToPiontArray(pointsStr);
    if (pointsArray == null || pointsArray.length == 0) return;
    map.setCenter(pointsArray[0]);
    map.removeOverlay(polyline);
    polyline.setPath(pointsArray);
    map.addOverlay(polyline);
}

function showPolygon(pointsStr) {
    var polygon = new BMap.Polygon([], { strokeColor: "green", fillColor: "green", strokeWeight: 1.0, strokeOpacity: 0.3, fillOpacity: 0.3 });
    var pointsArray = stringToPiontArray(pointsStr);
    if (pointsArray == null || pointsArray.length == 0) return;
    map.setCenter(pointsArray[0]);
    map.removeOverlay(polygon);
    polygon.setPath(pointsArray);
    map.addOverlay(polygon);
}

function stringToPiontArray(str) {
    var pointArray = new Array();
    var strs = str.split(";");
    for (i = 0; i < strs.length; i++) {
        var p = strs[i].split(",");
        pointArray.push(new BMap.Point(p[0], p[1]));
    }
    return pointArray;
}


var cppInvoker;
function ConfCppInvoker(obj) {
    cppInvoker = obj;
}

map.addEventListener("rightclick", function (c) {
    showPointValueInHtml(c);
    cppInvoker.ShowPointString(c.point.lng + "," + c.point.lat);
});

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
