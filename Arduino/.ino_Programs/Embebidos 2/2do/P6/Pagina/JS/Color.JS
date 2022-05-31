
function Color(){
  let red =  document.getElementById('redInput').value;

  let green =  document.getElementById('greenInput').value;

  let blue =  document.getElementById('blueInput').value;
  var text1 = document.getElementById('rgb1');
  //text1.value = rgbToHex(red, green, blue)
  text1.value = red + ", " + green + ", " + blue;

  var colorBox = document.getElementById('colorBox1');

  colorBox.style.backgroundColor = "rgb("+red+","+green+","+blue+")";

  
}

function componentToHex(c) {
  var hex = parseInt(c, 10).toString(16);
  return hex.length == 1 ? '0' + hex : hex;
}

function rgbToHex(r, g, b) {
   
  return "#" + componentToHex(r) + componentToHex(g) + componentToHex(b);
}
