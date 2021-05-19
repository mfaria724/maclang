# MACLang

*MACLang* será un lenguaje de programación desarrollado como requisito para el 
curso **CI4721 - Lenguajes de Programación II** dictado en la Universidad Simón
Bolívar en el período Mayo-Julio 2021.

## Especificación del Lenguaje

### Comentarios

Las líneas comentadas comenzarán por el caracter `&` y los bloques de 
comentarios serán inciadosy finalizados por `${` y `}&`, repectivamente.

Por ejemplo:

```
& comentario de línea
${
  comentario 
  multi
  línea
}&
```

### Tipos Primitivos

El lenguaje contará con 4 tipos primitivos: Enteros, Caracteres, Booleanos y 
Número de punto flotante (float).

Para la incialización de cada uno de ellos se usará la siguiente sintaxis:
```
Int i = 1; & entero
Char c = '1'; & caracter
Bool b = true; & booleano
Float f = 1.0; & flotante
```

Adicionalmente, se definirá el tipo de datos nulo como:

```
Int i = None;
```

### Tipos de Datos Compuestos

#### Arreglos

Para la declaración de arreglos se debe definir el tipo de datos primitivo al
cuál pertenecerán. Adicionalmente, existirán dos formas para indicar la cantidad
de elementos que poseerá el arreglo.

1. **No incializado**: Cómo la estructura no se encuentra inicializada, deberá 
indicarse la cantidad de elementos que poseerá la estructura de manera que se 
pueda reservar el espacio para los mismos. 

2. **Incializado**: Al inicializarse explícitamente el arreglo, podemos usar el
comodín `*` para que el deduzca la cantidad de elementos a través de la 
inicialización.

A continuación se muestran ejemplos para arreglos *inicializados* y *no inicializados*:

```
Int*10 array;
Int*? array2 = [0,1,2,42];
```

#### String

Las cadenas de caracteres serán definidad simplemente como un arreglo de 
caracteres. Sim embargo, el lenguaje incluirá el azúcar sintáctico para 
declararlo como un *String* directamente. Por ejemplo:

```
String hello = "world";  
Char*? hello = ['w', 'o', 'r', 'l', 'd'];
Char*5 hello = ['w', 'o', 'r', 'l', 'd'];
```

Es importante notar que para los caracteres se usarán comillas simples (`'`) 
mientras que los strings serán incializados con comillas dobles (`"`).

#### Registros

Los registros tendrán la siguiente estructura:

```
register <NAME> { 
  <TYPE> <FIELD> [= <DEFAULT>]; 
  ... 
}
```

Los valores por defecto deberán ser declarados en las útlimas posiciones para su
correcto funcionamiento. 

A continuación se muestran algunos ejemplos para el uso de estos registros:

```
register alo {
  Char F;
  String a =  "a";
}

alo ok;
alo.F = 'f';

alo fine = {'f'};
alo mmm = {'f', "a"};

alo*? wtf = [{'f', "a"}, mmm, fine]
```

#### Uniones

Las uniones tendrán la siguiente estructura, similar a la de los registros:

```
union <NAME> { 
  <TYPE> <FIELD>; 
  ... 
}
```

Algunos ejemplo de posibles usos de uniones:

```
union aja { Char F; Int x; }
aja ayno;
ayno~F = '2';
```

#### Apuntadores

TBD

### Instrucciones de Control de Flujo

#### Selección

Para la selección estará presente una instrucción clásica de tipo `if-then-elsif-else` 
como la que se muestra a continuación:

```
if <CONDITION1> then 
  <INSTRUCTION1>
elsif <CONDITION2> then
  <INSTRUCTION2>
else 
  <INSTRUCTION3>
fi
```

#### Bucle No Determinado

Para la selección estará presente una instrucción clásica de tipo `while-do-done` 
como la que se muestra a continuación:

while <CONDITION> 
do 
  <INSTRUCTION> 
  ...
done

#### Bucle Determinado

TBD

## Desarrolladores
* Amin Arriaga *(16-10075)*
* Manuel Faria *(15-10463)*
* Orlando Chaparro *(12-11499)*    

