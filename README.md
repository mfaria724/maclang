# **MACLang**

*MACLang* será un lenguaje de programación desarrollado como proyecto para el curso
**CI4721 - Lenguajes de Programación II** dictado en la Universidad Simón Bolívar en 
el período Abril-Julio 2021 por el profesor Ricardo Monascal.

## **Especificacion del Lenguaje**

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
* Números de punto flotante (IEEE 754) 
* Unit (Equivalente al tipo `void` en `C/C++`)

Para la inicialización de cada uno de ellos se usará la siguiente sintáxis:

```
Int i;          # Entero inicializado pero sin valor asignado.
Int j = 1;      # Entero inicializado y con valor asignado.
Char c = '1';   # Caracter
Bool b;         # Booleano
Float f = 1.0;  # Flotante
```

Todos estos tipos soportan la operación de asignación `=`, excepto `Unit`.

Las operaciones entre booleanos son

  * And: `&&`
  * Or: `||`
  * Not: `!`
  * Equiv: `==`

Las operaciones entre el resto de tipos de datos primitivos son

  * Suma: `+`
  * Resta: `-`
  * Multiplicación: `*`
  * División (no entera solo para los flotantes): `/`
  * Módulo (excepto para los flotantes): `%`

Con los caracteres será equivalente a operar sobre su representación en ASCII.

#### **Casteo Automático**

Adicionalmente, se definirá el casteo automático entre tipos primitivos de la 
siguiente manera:

* El número `0` representará al booleano `False` y viceversa (`0 <=> False`). En
contraste, cualquier otro número será casteado como el booleano `True`. 
(`(n != 0) => True`)
* Análogamente, el arreglo vacío será interpretado como el booleano `False` y cualquier
otra lista será casteada como el booleano `True`. (`[] => False` y 
`len(<lista>) != 0 => True`).
* El booleano `True` será interpretado como el número entero `1`. (`True => 1`).

### **Tipos de Datos Compuestos**

#### **Arreglos**

Todos los arreglos en el lenguaje son dinámicos, por lo que no hay que indicar su
longitud al momento de inicializarlo, pero si el tipo de los elementos que contiene.
Para ello, usamos la sintaxis `TYPE[]` donde `TYPE` es el tipo de dichos elementos, el
cual debe ser distinto de `Unit`. Por ejemplo:

```
Bool[] array;
Int[] integers = [1, 1, 2, 42, 69];
```

Las operaciones definidas sobre arreglos son:

  * Asignación `=`
  * Indexación: `[]`
  * Asignación indexada: `[]=`
  * Función longitud: `len()`
  * Función para agregar un elemento al final de la lista: `insert()`
  * Función para sacar un elemento del final de la lista: `pop()`

#### **Cadena de caracteres**

Las cadenas de caracteres serán definidas como arreglos de caracteres. Sin embargo, 
el lenguaje incluira azúcar sintáctico para declararlo como un tipo `String`, que 
sería equivalente al tipo `Char[]`. Por ejemplo:

```
String hello = "world";
String aja = ['a', 'y', ' ', 'n', 'o'];
Char[] ohno = "ohwell";
Char[] press = ['F'];
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
  Bool[] basaur;
  String erThings = "a";
}
alo ok;
ok.a = "sua";
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
* Amin Arriaga *(16-10075)*
* Manuel Faria *(15-10463)*
* Orlando Chaparro *(12-11499)*    

