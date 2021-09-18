# GSM-SIM-900L
<h1> Avisador de alarma activada a través de llamadas de telefono móvil </h1>

Actualmente la central de alarma hace las llamadas por telefono fijo. Esre proyecto sirve para para dar de baja el telefono fijo (20€/mes=) y hacer las llamadas a través de la línea móvil (0€/mes).

<h4> Funcionamiento </h4>
Mientras la alarma no está activada en Vin tenemos 0V y no se realiza ninguna acción.
Cuando se activa la alarma en Vin hay 12V, con el convertidos buck lo reducimos a 4.5V para que Arduino pueda leer ese voltaje (el voltaje máximo que puede leer son 5V).
Entonces Arduino detectará que el PIN A3 está en estado alto y realizará 5 llamadas a el numero1 y 5 llamadas a el numero 2. <br>
Cuando se activa Vin está activo durante 4 minutos, por lo tanto, al acabar las llamadas el Arduino hace una espera de 4 minutos para que no se reactive otra vez.<br>
 
<img src="./esquema.png">
