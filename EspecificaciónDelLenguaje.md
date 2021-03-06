# **MACLang**

*MACLang* es un lenguaje de programación desarrollado como proyecto para el curso
**CI4721 - Lenguajes de Programación II** dictado en la Universidad Simón Bolívar en 
el período Abril-Julio 2021 por el profesor Ricardo Monascal.

## **Especificación del Lenguaje**

### **Comentarios**

Los comentarios de linea iniciaran con el caracter `#`, mientras que los comentarios
multilinea serán iniciados y finalizados por `${` y `}$` respectivamente. Por ejemplo

```
# Comentario de linea.
${
  Comentario
  multi
  linea
}$
```

### **Tipos Primitivos**

El lenguaje contará con 4 tipos primitivos: 
* Enteros (Complemento a 2) 
* Caracteres (Unicode) 
* Booleanos (`True` y `False`) 
* Números de punto flotante (IEEE 754, de precisión simple) 
* Unit (Equivalente al tipo `void` en `C/C++`)

Para la inicialización de cada uno de ellos se usará la siguiente sintáxis:

```
let Int i;          # Entero inicializado pero sin valor asignado.
let Int j = 1;      # Entero inicializado y con valor asignado.
let Char c = '1';   # Caracter
let Bool b;         # Booleano
let Float f = 1.0;  # Flotante
```

Todos estos tipos soportan la operación de asignación `=`, excepto `Unit`.

Las relaciones de comparación entre los tipos primitivos serán las siguientes:

Las operaciones entre booleanos se definen de la siguiente manera:

  * Conjunción: `&&`
  * Disyunción: `||`
  * Negación: `!`
  
Las operaciones de comparación entre todos los datos primitivos se definen de la
siguiente manera:  
  * Equivalencia: `==`
  * Inequivalencia: `!=`

Las operaciones de comparación entre enteros, flotantes y caracteres se definen
de la siguiente manera:
  * Mayor que: `>`
  * Menor que: `<`
  * Mayor o igual que: `>=`
  * Menor o igual que: `<=`

Las operaciones entre el resto de tipos de datos primitivos son

  * Suma: `+`
  * Resta: `-`
  * Multiplicación: `*`
  * División (no entera solo para los flotantes): `/`
  * Módulo (excepto para los flotantes): `%`

### **Tipos de Datos Compuestos**

#### **Arreglos**

Todos los arreglos en el lenguaje son estáticos, por lo que hay que indicar su
longitud al momento de inicializarlo.
Para ello, usamos la sintaxis `TYPE[N]` donde `TYPE` es el tipo de dichos elementos, 
el cual debe ser distinto de `Unit`, y `N` el número de elementos que tendrá
el arreglo. Por ejemplo:

```
Bool[3] array;
Int[5] integers = [1, 1, 2, 42, 69];
```

Las operaciones definidas sobre arreglos son:

  * Asignación `=`
  * Indexación: `[]`
  * Asignación indexada: `[]=`
  * Función longitud: `len()`

#### **Cadena de caracteres**

Las cadenas de caracteres serán definidas como arreglos de caracteres. Sin embargo, 
el lenguaje incluira azúcar sintáctico para declararlo como un tipo `String`, que 
sería equivalente al tipo `Char[]`. Por ejemplo:

```
String hello = "world";
String aja = ['a', 'y', ' ', 'n', 'o'];
Char[6] ohno = "ohwell";
Char[1] press = ['F'];
```

Por lo tanto, el tipo `String` tiene definidas las mismas operaciones que los arreglos.
Es importante notar que para los caracteres se usarán comillas simples (`'`), 
mientras que para las cadenas de caracteres se usarán comillas dobles (`"`).

#### **Registros**

La definición de registros seguirá la siguiente estructura:

```
register <NAME> {
  <TYPE> <FIELD> [= <DEFAULT>];
  ...
}
```

Los valores por defecto deberan ser declarados en las últimas posiciones del registro
para su correcto funcionamiento. Una vez definidos se pueden usar como un tipo mas del
lenguaje. Las únicas operaciones definidas sobre los registros son el acceso a campo 
(`.`) y la asignación. Por ejemplo:

```
register alo {
  Char mander;
  Bool[4] basaur;
  String erThings = "a";
}
alo ok;
ok.erThings = "sua";
```

Intentar realizar otra operación a parte de la asignación sobre un campo no definido
producira un error de ejecución.

#### **Uniones**

La definición de uniones seguirá la siguiente estructura:

```
union <NAME> {
  <TYPE> <FIELD>;
  ...
}
```

Una vez definidos se pueden usar como un tipo mas del lenguaje. Las únicas operaciones 
definidas sobre las uniones son el acceso a campo (`.`) y la asignación. Asignarle
un valor a un campo causa la indefinición del resto. Intentar realizar otra operación 
a parte de la asignación sobre un campo no definido producira un error de ejecución.
Ejemplo de una unión:

```
union frag {
  Bool Kevin;
  Char Dennis;
  Int Patricia;
  Float Hedwig;
  String Bestia

}
frag F;
F.Patricia = -1;
```

#### **Apuntadores**

Los apuntadores se definen como `^TYPE`, lo que significa que es un apuntador a una
variable de tipo `TYPE`. Cumplen las siguientes características:

  * Las únicas operaciones que soportan los apuntadores son la asignación `=` y la 
  desreferenciación `^`. 
  * Al indicar un tipo, las referencias `^` tienen más precedencia que los arreglos 
  `[]`, es decir, `^TYPE[]` es equivalente a `(^TYPE)[]`.
  * Inversamente, la desrefenciación tiene menor precedencia que la indexación o 
  la asignación indexada. Es decir, `^VAR[i]` es equivalente a  `^(VAR[i])`.
  * Como ya vimos, se puede modificar esta precedencia usando paréntesis. Por ejemplo 
  `^(TYPE[])` indica el tipo apuntador a un arreglo de variables tipo `TYPE`.
  * Para crear una referencia de un tipo se usa la palabra clave `new`, por ejemplo:

```
^Int ref = new Int;
```
  * El tipo `^Unit` es equivalente a `void*` de  *C/C++*, es decir, se puede usar como
  un apuntador a cualquier tipo.
  * Como contraparte del `new`, existirá la palabra reservada `forget` para liberar
  la memoria ocupada por una referencia. Por ejemplo:

```
forget ref;
```

### Instrucciones de Control de Flujo

#### **Selección**

Sintáxis:
```
if <CONDITION1> then
  <INSTRUCTION>
  ...
[
elsif <CONDITION2> then
  <INSTRUCTION>
  ...
]
[
else
  <INSTRUCTION>
  ...
]
done
```

#### **Bucle No Determinado**

Sintaxis:

```
while <CONDITION> do
  <INSTRUCTIONS>
done
```

#### **Bucle Determinado**

Sintaxis:

```
for (<INT_VAR>; <BEGIN>; <END> [; <STEP>]) do
  <INSTRUCTIONS>
done
```

#### **Funciones**

Sintaxis:

```
<NAME>(<TYPE> [@]<ARG>, ...) => <TYPE> {
  <INSTRUCTIONS>;
  ...
  return <TYPE_RESULT>;
}

<NAME>(<PARAM>, ...);
```

Colocarle `@` como prefijo al nombre del argumento indica que se pasará como 
referencia. En caso de no usarlo se pasará por valor.

#### **Procedimientos**

Sintaxis:

```
<NAME>(<TYPE> [@]<ARG>, ...) {
  <INSTRUCTIONS>
}

<NAME>(<PARAM>, ...);
```

Colocarle `@` como prefijo al nombre del argumento indica que se pasará como 
referencia. En caso de no usarlo se pasará por valor.

### Entrada y Salida

Se definirán las siguientes funciones:
* `Char readchar(Unit)`: Lee un caracter de la entrada.
* `Unit print(String)`: Imprime un string en la salida estándar. 

## Desarrolladores
* Amin Arriaga *(16-10072)*
* Manuel Faria *(15-10463)*
* Orlando Chaparro *(12-11499)*    

