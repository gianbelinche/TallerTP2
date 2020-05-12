# TallerTP2
 
Nombre: Belinche Gianluca Ernesto

Padrón: 102674

[Link al repositorio](https://github.com/gianbelinche/TallerTP2.git) 

## Descripción del trabajo

En este trabajo se genero una solución al problema de simular el comportamiento de un pequeño poblado.
Para lograrlo se uitilizo un modelo que será descripto a continuación:

Debido al tamaño del modelo, se lo separara en distintas partes, para su mas facil explicación.

### Sección Visible

Desde el punto de vista del usuario, solo se posee el conocimiento de las siguiente clases:

    - ColaBloqueante
    - Inventario
    - Trigo
    - Madera
    - Carbon
    - Hierro
    - ParseadorTrabajadores
    - ParseadorMateriasPrimas
    - PuntosDeBeneficio
    - ManejadorTrabajadores

Pasare a explicar cada uno de ellos,

Los mas sencillos, son los 4 recursos (Trigo,Madera,Carbon y Hierro), los 4 heredan de una clase común llamada Recurso, y el proposito
de estas clases es el de representar el propio recurso, y posteriormente, comunicarle al inventario que recurso será almacenado.

La ColaBloqueante se encarga de repartir los recursos, con un modelo FIFO, que además implementa un mutex y una condition variable, lo cual permite que distintos threads puedan acceder a ella sin generar race conditions, y gracias a la condition variable, se logra optimizar la entrada de los threads, notificandolos en cuanto un nuevo recurso es encolado.

El inventario permite almacenar los distintos recursos, donde los Recolectores son los encargados de almacenarlos, y los Productores de utilizarlos, (estas dos clases se explicaran mas adelante), también se utiliza un mutex y una condition variable, para que no se superpongan los distintos almacenamientos y extracciones de recursos.

La ultima clase con un mecanismo similar a las dos anteriores es PuntosDeBeneficio, que internamente es un contador que dependiendo de que productor lo llame, aumenta en un numero diferente de puntos, de nuevo, tambien utiliza mutex y condition variable para su correcta utilización.

Luego tenemos una clase abstracta llamada Parseador, de la cual descienden, ParseadorTrabajadores y ParseadorMateriasPrimas, estas se encargan de parsear los archivos correspondientes, la primera obtiene las cantidades de cada trabajador, mientras que la segunda va leyendo el archivo de los recursos, y dependiendo que recurso sea, lo va encolando en la ColaBloqueante que corresponda.

Por ultimo en este apartado, esta la clase ManejadorTrabajadores, que se encarga de inicializar a los distintos Recolectores y Productores, que pasaran a ser explicados en el proximo apartado.

### Sección No Visible

Ya por fuera del conocimiento directo del usuario, se encuentran las siguientes clases:

    - Recolector
    - Agricultor
    - Lenador
    - Minero
    - Productor
    - Armero
    - Cocinero
    - Carpintero

    - RecolectorInterno
    - ProductorInterno
    - ArmeroInterno
    - CarpinteroInterno
    - CocineroInterno

Primero explicaré el porque de la decisión de generar estas clases que parecerían ser redundantes,

Las clases Recolector y Productor encapsulan los threads para su mas sencilla utilización, los derivados de Recolector (Agricultor, Lenador y Minero) no agregan nueva logica, simplemente estan ahi para ajustarse mejor a la idea del enunciado, y sea mas facil diferenciarlos, en cambio los derivados de Productor (Armero, Cocinero y Carpintero) si agregan nueva logica, que es la de poder inicializar los threads con los correpondientes ***Interno, que son los que eventualmente realizan el trabajo que uno hubiera esperado en este tipo de clases.

La clase RecolectorInterno, es la que se le pasa a los threads generados en Recolector, para que este llame al operator(), en donde se realiza un desencolar de la ColaBloqueante que se le haya proporcionado, y luego se agrega al inventario el Recurso extraido.

La clase ProductorInterno, es la que se le pasa a los threads generados en los derivados de Productor, pero cada derivado de ProductorInterno en particular, posee una logico un poquito diferente, en estos, se extrae un recurso del inventario, que depende de que ProductorInterno sea el que lo haga, y luego se aumentan la cantidad de puntos de beneficio, también dependiendo de quien lo haga.

## Diagramas

