# Taller-3-Estructura
Ejecucion del codigo:

g++ -IInclude Source/Transaccion.cpp Source/NodoAVL.cpp Source/Nodo.cpp Source/Criterio.cpp Source/ArbolABB.cpp Source/ArbolAVL.cpp Source/main.cpp -o programa

una ves compilado: ./programa

Integrantes: 

Benjamín Antonio Riquelme Salgado, RUT: 21.545.470-3, correo institucional: benjamin.riquelme@alumnos.ucn.cl

Manuel Ignacio Jerez Mattus, RUT: 21.353.476-9, correo institucional: manuel.jerez@alumnos.ucn.cl

Base de datos:
Transaccion 1:{ID:1,Cuenta de origen: 1234567890,Cuenta de destino: 0987654321,Monto: 1000.00,Ubicacion: Argentina,Fecha: 2023-07-01,Hora: 10:30}
Transaccion 2:{ID:2,Cuenta de origen: 2345678901,Cuenta de destino: 1098765432,Monto: 2500.00,Ubicacion: Chile,Fecha: 2023-07-02,Hora: 11:00}
Transaccion 3:{ID:3,Cuenta de origen: 3456789012,Cuenta de destino: 2109876543,Monto: 1500.50,Ubicacion: Chile,Fecha: 2023-07-03,Hora: 12:15}
Transaccion 4:{ID:4,Cuenta de origen: 2361873612,Cuenta de destino: 3737327732,Monto: 1000.00,Ubicacion: Bolivia,Fecha: 2023-07-03,Hora: 12:17}
Transaccion 5:{ID:5,Cuenta de origen: 4567890123,Cuenta de destino: 3210987654,Monto: 2000.00,Ubicacion: Argentina,Fecha: 2023-07-04,Hora: 09:45}
Transaccion 6:{ID:6,Cuenta de origen: 5678901234,Cuenta de destino: 4321098765,Monto: 1750.75,Ubicacion: Bolivia,Fecha: 2023-07-04,Hora: 10:30}
Transaccion 7:{ID:7,Cuenta de origen: 6789012345,Cuenta de destino: 5432109876,Monto: 3000.00,Ubicacion: Chile,Fecha: 2023-07-05,Hora: 13:00}
Transaccion 8:{ID:8,Cuenta de origen: 7890123456,Cuenta de destino: 6543210987,Monto: 1250.00,Ubicacion: Argentina,Fecha: 2023-07-05,Hora: 14:25}
Transaccion 9:{ID:9,Cuenta de origen: 8901234567,Cuenta de destino: 7654321098,Monto: 2750.25,Ubicacion: Bolivia,Fecha: 2023-07-06,Hora: 15:40}
Transaccion 10:{ID:10,Cuenta de origen: 9012345678,Cuenta de destino: 8765432109,Monto: 3500.00,Ubicacion: Chile,Fecha: 2023-07-06,Hora: 16:55}
Transaccion 11:{ID:11,Cuenta de origen: 1230984567,Cuenta de destino: 9876543210,Monto: 1450.00,Ubicacion: Argentina,Fecha: 2023-07-07,Hora: 09:10}
Transaccion 12:{ID:12,Cuenta de origen: 2341095678,Cuenta de destino: 1987654321,Monto: 2250.00,Ubicacion: Bolivia,Fecha: 2023-07-07,Hora: 10:35}
Transaccion 13:{ID:13,Cuenta de origen: 3452106789,Cuenta de destino: 2198765432,Monto: 1950.50,Ubicacion: Chile,Fecha: 2023-07-08,Hora: 11:50}
Transaccion 14:{ID:14,Cuenta de origen: 4563217890,Cuenta de destino: 3219876543,Monto: 3200.00,Ubicacion: Argentina,Fecha: 2023-07-08,Hora: 13:05}
Transaccion 15:{ID:15,Cuenta de origen: 5674328901,Cuenta de destino: 4321987654,Monto: 2750.75,Ubicacion: Bolivia,Fecha: 2023-07-09,Hora: 14:20}

PD: quiero hacer una explciacion de criterios, existe una clase criterios que contiene como dice su nombre los criterios para considerar si una transaccion es fraudulenta o no. 
dado esta misma explicacion, nosotros para el item de transacciones en corto periodo de tiempo, tomamos un criterio de 5min, toda transacciones seguidas en menos de 5min se consideran fraudulentas.(fin de la aclaracion)

Criterio{Monto limine criterio: 100000,Ubicacion criterio:CHILE,Hora inicio Criterio:0,Hora fin criterio:6}



