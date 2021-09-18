# GSM-SIM-900L
<h1> a </h1>

Este proyecto sirve avisar por llamada telefonica cuando la alarma se activa. <br>
<br>
Mientras la alarma no está activada en Vin tenemos 0V y no se realiza ninguna acción.<br>
Cuando se activa la alarma en Vin hay 12V, con el convertidos buck lo reducimos a 4.5V para que Arduino pueda leer ese voltaje.<br>
Arduino detectará que el PIN A3 está en estado alto y realizará 5 llamadas a el numero1 y 5 llamadas a el numero 2. <br>
Cuando se activa Vin está activo durante 4 minutos, por lo tanto, al acabar las llamadas el Arduino hace una espera de 4 minutos para que no se reactive otra vez.<br>
 



<img src="./esquema.png">
