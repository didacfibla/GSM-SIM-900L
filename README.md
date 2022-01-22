# GSM-SIM-900L
<h1> Arduino GSM </h1>

<h3> Descripción y objetivo del proyecto </h3>

Senscillo programa desarrollado en C++ que permite realizar llamadas telefónicas por la línea movil gsm cuando el Arduino Nano detecta que una entrada que está continuamente leyendo pasa a estado alto. <br>

<h3> Componentes necesarios </h3>
<ul> 
 <li> Arduino Nano V3.0. </li>
 <li> SiM 900 L. (Módulo encargado de realizar las llamadas)</li>
 <li> 2 baterías de litio 18650. (3,7V) </li>
 <li> BMS 2s. (Gestor de baterías que protege ante sobrecargas, sobredescargas, cortocircuitos y además equilibra la carga entre ambas celdas)</li>
 <li> 1 resistencia de 10 kΩ </li>
 <li> Interruptor. </li>
</ul>


<h3> Funcionamiento </h3>
El Arduino nano está de forma permanente realizando una lectura de una entrada digital. Esta entrada digital está conectada a una salida del sistema de alarma que solo se activa cuando se detecta una incidencia, cuando se activa circulan [~4.5, 5V] <br>
Después de detectar que la entrada está en estado alto el programa realiza X número de llamadas a distintos numeros de telefono para avisar de la intrusión.

 <br>
<img src="./esquema.png">
El esquema está pendiende de correción
