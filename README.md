# C-Lab5


![C](https://img.shields.io/badge/Language-C99-A8B9CC?style=flat&logo=c&logoColor=black)
![Linux](https://img.shields.io/badge/Target-Linux-FCC624?style=flat&logo=linux&logoColor=black)
![GitHub Codespaces](https://img.shields.io/badge/Environment-GitHub%20Codespaces-181717?style=flat&logo=github&logoColor=white)
![Educational](https://img.shields.io/badge/Purpose-Educational-6A5ACD?style=flat)

Piąte laboratorium z języka C, przygotowane do pracy w środowisku GitHub Codespaces.



## Zadania

### 1. Struktura opisująca działanie

Plik: `src/zad01.c`.

Program startowy zawiera strukturę `Book` opisującą książkę. Przeanalizuj definicję struktury, sposób inicjalizacji zmiennej oraz dostęp do jej pól za pomocą operatora `.`.

Przerób program tak, aby przechowywał opis działania arytmetycznego.

Zdefiniuj strukturę `Operation` z polami:

| Pole | Typ | Znaczenie |
|---|---|---|
| `left` | `float` | Lewy argument działania |
| `right` | `float` | Prawy argument działania |
| `operator` | `char` | Znak działania |

W funkcji `main` utwórz zmienną tej struktury opisującą działanie `15.5 - 4.25`. Wypisz wartości jej pól.

Dostosuj asercje z programu startowego tak, aby sprawdzały wartości zapisane we wszystkich trzech polach.

#### Oczekiwane wyjście

```text
left: 15.5000
right: 4.2500
operator: -
```

### 2. Obliczanie działania zapisanego w strukturze

Plik: `src/zad02.c`.

Skopiuj rozwiązanie zadania 1. Dodaj funkcję, która przyjmuje strukturę opisującą działanie i zwraca jego wynik:

```c
float calculate_operation(struct Operation operation);
```

Wewnątrz funkcji sprawdź pole `operator` za pomocą `switch`. Obsłuż operatory `+`, `-`, `*` i `/`, wykorzystując funkcje arytmetyczne z poprzedniego laboratorium:

```c
float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);
```

Argumenty działania pobieraj z pól `left` i `right`. Dla odejmowania i dzielenia zachowaj kolejność: `left - right` oraz `left / right`. Przyjmujemy, że operator jest poprawny, a dzielnik różny od zera.

Utworz struktury pozwalające obliczyc:

- dodawanie: `2.5 + 3.25`,
- odejmowanie: `15.5 - 4.25`,
- dzielenie: `9.0 / 4.0`,
- mnożenie: `2.5 * 4.0`.

Dla każdej z nich wywołaj `calculate_operation` i wypisz wynik.

#### Oczekiwane wyjście

```text
result: 5.7500
result: 11.2500
result: 2.2500
result: 10.0000
```


### 3. Struktura zawierająca inną strukturę

Plik: `src/zad03.c`.

Program startowy opisuje prostokąt za pomocą dwóch punktów. Typ `Rectangle` zawiera dwa pola typu `Point`. Zapis `rectangle.first.x` pozwala odwołać się do pola `x` punktu `first` należącego do prostokąta `rectangle`.

Spróbuj zastosować ten mechanizm do opisania wyrażenia:

```text
(2 + 0) * (4 + 3)
```

```text
        *
       / \
      +   +
     / \ / \
    2   0 4   3
```

Chcemy, aby argumentami wyrażenia mogły być kolejne wyrażenia. Dodaj poniższą definicję i spróbuj skompilować program:

```c
typedef struct Expression {
    char operator;
    struct Expression left;
    struct Expression right;
} Expression;
```

Dlaczego `Rectangle` może zawierać pola typu `Point`, a `Expression` nie może zawierać pól własnego typu? Co zawierałoby pole `left`, a następnie jego własne pole `left`? Czy można określić rozmiar takiej struktury?

Jak zmienić pola `left` i `right`, aby przechowywały odwołania do innych obiektów `Expression`, zamiast zawierać te obiekty bezpośrednio?

Popraw definicję tak, aby program się kompilował.

Utwórz funkcję:

```c
float calculate_node(Node node);
```

bazując na `calculate_operation` z zadania 2.

Wywołaj funkcję dla kolejnych węzłów.

#### Oczekiwane wyjście

```text
result: 2.0000
result: 14.0000
```

### 4. Określanie rodzaju danych za pomocą enum

Plik: `src/zad04.c`.

Wykorzystaj typy `Operation` i `Expression` z zadania 3. Przygotuj strukturę, która może opisywać pojedynczą liczbę albo wyrażenie. Informację o rodzaju zapisanych danych przechowaj za pomocą typu wyliczeniowego.

Zdefiniuj typ `NodeType` za pomocą `typedef enum`, nadając jego wartościom nazwy:

| Wartość | Znaczenie |
|---|---|
| `NODE_VALUE` | Przechowywana jest liczba |
| `NODE_EXPRESSION` | Przechowywane jest wyrażenie |

Następnie zdefiniuj typ `Node` jako strukturę z polami:

| Pole | Typ | Znaczenie |
|---|---|---|
| `type` | `NodeType` | Rodzaj zapisanych danych |
| `value` | `float` | Wartość liczbowa |
| `expression` | `Expression` | Wyrażenie zbudowane jak w zadaniu 3 |

W funkcji `main` utwórz dwie zmienne typu `Node`:

- pierwszą oznacz jako `NODE_VALUE` i przypisz jej wartość `2`;
- drugą oznacz jako `NODE_EXPRESSION` i zapisz w niej wyrażenie `(0 + 2) * (4 + 3)`.


W funkcji sprawdź pole `type` za pomocą `switch`:

- dla `NODE_VALUE` zwróć zawartość pola `value`;
- dla `NODE_EXPRESSION` oblicz wartość pola `expression`, korzystając z funkcji `calculate_node` z zadania 3.


### 5. Unia przechowująca różne rodzaje danych

Plik: `src/zad05.c`.

Program startowy zawiera unię `ExampleData` z polami typu `unsigned char` i `float`. Uruchom program i porównaj rozmiary obu typów z rozmiarem unii.

Przeanalizuj przypisania w funkcji `main`. Pola unii współdzielą pamięć: program najpierw przechowuje w niej znak, a następnie liczbę zmiennoprzecinkową.

Dla porównania zdefiniuj typ `ExampleStruct` jako strukturę zawierającą takie same pola jak `ExampleData`. Dodaj wypisywanie jej rozmiaru. Porównaj rozmiar struktury z rozmiarem unii.

Następnie wykorzystaj unię do przechowywania liczby całkowitej albo zmiennoprzecinkowej.

Zdefiniuj typ `NumberData` za pomocą `typedef union`:

| Pole | Typ |
|---|---|
| `integer` | `int` |
| `real` | `float` |

Wykorzystaj mechanizm z poprzedniego zadania, aby zapisać informację o rodzaju przechowywanej liczby. Zdefiniuj typ wyliczeniowy `NumberType` z wartościami `NUMBER_INTEGER` i `NUMBER_REAL` oraz strukturę `Number`:

| Pole | Typ | Znaczenie |
|---|---|---|
| `type` | `NumberType` | Rodzaj zapisanej liczby |
| `data` | `NumberData` | Przechowywana liczba |

Dodaj funkcję:

```c
void print_number(Number number);
```

W funkcji sprawdź pole `type` za pomocą `switch` i wypisz odpowiednie pole unii.

W `main` utwórz zmienną typu `Number`. Zapisz w niej liczbę całkowitą `12` wraz z odpowiednim znacznikiem i wywołaj `print_number`. Następnie zapisz w tej samej zmiennej liczbę zmiennoprzecinkową `2.5f`, zaktualizuj znacznik i ponownie wywołaj funkcję.

#### Wyjście funkcji print_number

```text
integer: 12
real: 2.5000
```


### 6. Unia w strukturze węzła

Plik: `src/zad06.c`.

W zadaniu 4 struktura `Node` zawierała osobne pola `value` i `expression`. Pole `type` określało, z którego z nich korzysta funkcja `calculate_node`.

Wykorzystaj unię poznaną w zadaniu 5, aby oba warianty współdzieliły pamięć.

Zdefiniuj typ `NodeData` za pomocą `typedef union`:

| Pole | Typ | Znaczenie |
|---|---|---|
| `value` | `float` | Wartość liczbowa |
| `expression` | `Expression` | Wyrażenie |

Zmień strukturę `Node`, aby zawierała pola:

| Pole | Typ | Znaczenie |
|---|---|---|
| `type` | `NodeType` | Rodzaj zapisanych danych |
| `data` | `NodeData` | Liczba albo wyrażenie |

Dostosuj funkcję `calculate_node` oraz przypisania w `main` do nowej budowy struktury. Dostęp do liczby będzie odbywał się przez `node.data.value`, a do wyrażenia przez `node.data.expression`.

Zachowaj przykłady z zadania 4, wykryj typ danych uzywajac pola type. Oblicz ich wartości za pomocą `calculate_node` i wypisz wyniki.

#### Oczekiwane wyjście

```text
result: 2.0000
result: 14.0000
```