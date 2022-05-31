


// function Connect(){
//     if (window.XMLHttpRequest){
//         xmlhttp = new XMLHttpRequest();
//     }

//     else{
//         xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
//     }

//     var PageToSendTo = "../TX.php?";
//     var Vel = document.getElementById('#Velocidad').value;
//     var State = document.getElementById('#State').value;
//     var Dir = document.getElementById('#Dir').value;
//     var TagVel= "Vel=";
//     var TagState= "&&State=";
//     var TagDir= "&&Dir=";
//     var UrlToSend = PageToSendTo + TagVel + Vel + TagState + State + TagDir + Dir;


//     xmlhttp.open("POST", UrlToSend, false);
//     xmlhttp.send();
// }


function Connect() {
    var form = document.getElementById('formulario');
    console.log(form);
    var datos = new FormData(form);
    //console.log(datos);
    console.log(datos.get('Vel'));
    console.log(datos.get('State'));
    console.log(datos.get('Dir'));
    fetch('../update_values.php', {
        method: 'POST',
        body: datos
    })
        .then(response => response.json())
        .then(data => {
            console.log(data);
        })
}