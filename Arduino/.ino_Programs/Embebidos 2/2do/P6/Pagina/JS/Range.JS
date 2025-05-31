//para el input
var Input = document.querySelector('#redInput');
Input.style.setProperty("--value", Input.value);

if (Input) {
  var w = parseInt(window.getComputedStyle(Input, null).getPropertyValue('width'));

Input.addEventListener("input", function(evt) {
  Input.style.setProperty("--value", Input.value);
},false);

//para la etiqueta
var etq = document.querySelector('.etiqueta');
if (etq) {
  
  etq.innerHTML = Math.round(Number(Input.value*100/255).toPrecision(15))+"%";

  var pxls = w / 255;

  etq.style.left = ((Input.value * pxls) - 15) + 'px';

  Input.addEventListener('input', function() {
    
    etq.innerHTML = Math.round(Number(Input.value*100/255).toPrecision(15))+"%";
    etq.style.left = ((Input.value * pxls) - 15) + 'px';

  }, false);
}
}


var Input2 = document.querySelector('#greenInput');
Input2.style.setProperty("--value", Input2.value);

if (Input2) {
  var w2 = parseInt(window.getComputedStyle(Input2, null).getPropertyValue('width'));

Input2.addEventListener("input", function(evt) {
  Input2.style.setProperty("--value", Input2.value);
},false);

//para la etiqueta
var etq2 = document.querySelector('.etiquetaG');
if (etq2) {
  
  etq2.innerHTML = Math.round(Number(Input2.value*100/255).toPrecision(15))+"%";

  var pxls2 = w2 / 255;

  etq2.style.left = ((Input2.value * pxls2) - 15) + 'px';

  Input2.addEventListener('input', function() {
    
    etq2.innerHTML = Math.round(Number(Input2.value*100/255).toPrecision(15))+"%";
    etq2.style.left = ((Input2.value * pxls2) - 15) + 'px';

  }, false);
}
}


var Input3 = document.querySelector('#blueInput');
Input3.style.setProperty("--value", Input3.value);

if (Input3) {
  var w3 = parseInt(window.getComputedStyle(Input3, null).getPropertyValue('width'));

Input3.addEventListener("input", function(evt) {
  Input3.style.setProperty("--value", Input3.value);
},false);

//para la etiqueta
var etq3 = document.querySelector('.etiquetaB');
if (etq3) {
  
  etq3.innerHTML = Math.round(Number(Input3.value*100/255).toPrecision(15))+"%";

  var pxls3 = w3 / 255;

  etq3.style.left = ((Input3.value * pxls3) - 15) + 'px';

  Input3.addEventListener('input', function() {
    
    etq3.innerHTML = Math.round(Number(Input3.value*100/255).toPrecision(15))+"%";
    etq3.style.left = ((Input3.value * pxls) - 15) + 'px';

  }, false);
}
}

//To-Do -> apply POO to optimize the code.
