//para el input
var Input = document.querySelector('#Velocidad');
Input.style.setProperty("--value", Input.value);

if (Input) {
  var w = parseInt(window.getComputedStyle(Input, null).getPropertyValue('width'));

Input.addEventListener("input", function(evt) {
  Input.style.setProperty("--value", Input.value);
},false);

//para la etiqueta
var etq = document.querySelector('.etiqueta');
if (etq) {
  
  etq.innerHTML = Math.round(Number(Input.value).toPrecision(15))+"%";

  var pxls = w / 100;

  etq.style.left = ((Input.value * pxls) - 14) + 'px';

  Input.addEventListener('input', function() {
    
    etq.innerHTML = Math.round(Number(Input.value).toPrecision(15))+"%";
    etq.style.left = ((Input.value * pxls) - 14) + 'px';

  }, false);
}
}

