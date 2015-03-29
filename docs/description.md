## Wizard BASIC 2

Wizard BASIC 2 &mdash; компилируемый высокоуровневый язык программирования.
Обладает строгой статической типизацией.

### Исходники

Файлы исходного кода должны быть в кодировке ASCII.

### Ключевые слова

6 ключевых слов:

	DIM GOTO IF LET REM THEN

### Типы

Типизация: строгая статическая.

#### Void

Фиктивный тип, константа или переменная не могут его иметь. Используется только
как тип возвращаемого значения у функций, которые ничего не возвращают.

#### Числа

Тип: с плавающей запятой, 4 байт.

Копирование: по значению.

Хранение: на стеке.

Определение: `? /(0|[1-9]\d*)(\.\d+)?/i ?`.

#### Массивы

Тип: массив статической длины; длина массива должна быть известна уже на стадии
компиляции.

Копирование: по ссылке.

Хранение:

* ссылки &mdash; на стеке;
* значения &mdash; в куче.

Определение: оператор `"DIM", identifier, "[", size, "]"`.

#### Строки

Строками являются массивы, хранящие коды символов. Используется кодировка ASCII.

Определение: оператор `"DIM", identifier, "=", ? /"(\\.|[^"])*"/ ?`.

#### Файлы

Тип: файлы ОС; доступ по хэндлеру; хэндлер представляет собой число (см. выше).

Копирование: хендлера &mdash; по значению.

Хранение: хендлера &mdash; на стеке.

#### Модели

Тип: трёхмерный графический объект; доступ по хэндлеру; хэндлер представляет
собой число (см. выше).

Копирование: хендлера &mdash; по значению.

Хранение: хендлера &mdash; на стеке.

#### Звуки

Тип: двумерный или трёхмерный источник звука; доступ по хэндлеру; хэндлер
представляет собой число (см. выше).

Копирование: хендлера &mdash; по значению.

Хранение: хендлера &mdash; на стеке.

### Операции

Перечислены в порядке убывания приоритета.

Приоритет | Операция | Описание | Ассоциативность | Типы
--- | --- | --- | --- | ---
1 | `[]` | доступ к элементам массива | левая | массивы
2 | `*` | умножение | левая | числа
2 | `/` | деление | левая | числа
3 | `+` | сложение | левая | числа
3 | `-` | вычитание | левая | числа

### Вызов функции

	identifier, "(", [expression, {",", expression}], ")"

Является выражением.

### Операторы

Любой оператор записывается на отдельной строке и обязан предваряться меткой.

#### Метка

	`? /[1-9]\d*/ ?`

Два оператора не могут иметь одинаковую метку. Метки должны идти в порядке
возрастания.

#### Объявление переменных и присваивание

	"LET", expression, "=", expression, line break

В качестве левого `expression` могут использоваться переменные типа число и
элементы массивов.

#### Управляющие конструкции

Метка `label` должна быть существующей меткой (см. выше) некоторой строки в
программе.

##### Безусловный переход

	`"GOTO", label, line break`

##### Условный переход

	"IF", expression, comparison, expression, "THEN", label, line break

Операция `comparison` может быть трёх видов:

Обозначение | Значение | Типы
--- | --- | ---
`<` | меньше | числа и массивы
`=` | равно | числа и массивы
`>` | больше | числа и массивы

Операция `comparison` может использоваться только как часть оператора условного
перехода. Частью выражения она быть не может.

#### Комментарий

Комментарием является любая строка, начинающаяся с ключевого слова `REM`.

Является оператором.

### Стандартная библиотека

#### Модуль Math

* `NUMBER SIN(NUMBER)`;
* `NUMBER COS(NUMBER)`;
* `NUMBER TAN(NUMBER)`;
* `NUMBER ATN(NUMBER)`;
* `NUMBER EXP(NUMBER)`;
* `NUMBER LOG(NUMBER)`;
* `NUMBER SQR(NUMBER)`;
* `NUMBER ABS(NUMBER)`;
* `NUMBER INT(NUMBER)` &mdash; возвращает целую часть числа.

#### Модуль System

* `NUMBER RND(VOID)` &mdash; возвращает случайное число в диапазоне [0; 1];
* `NUMBER TIMER(VOID)` &mdash; возвращает время, прощедшее с момента запуска
программы в секундах; число дробное, используется таймер повышенной точности;
* `VOID PRINT(NUMBER number)`;
* `VOID PRINT(ARRAY string)`;
* `VOID PRINT(NUMBER file_id, ARRAY byte_sequence)`;
* `NUMBER OPEN(ARRAY filename, NUMBER mode)` &mdash; режим открытия может быть:
	* 0 (чтение);
	* 1 (запись);
	* 2 (дополнение);
* `NUMBER INPUT(NUMBER file_id)` &mdash; читает из файла 1 байт;
* `VOID CLOSE(NUMBER file_id)`.

#### Модуль Graphics

* `NUMBER SCREEN_WIDTH(VOID)`;
* `NUMBER SCREEN_HEIGHT(VOID)`;
* `VOID POSITION_CAMERA(NUMBER x, NUMBER y, NUMBER z)`;
* `VOID ROTATION_CAMERA(NUMBER x, NUMBER y, NUMBER z)`;
* `VOID FOG(NUMBER mode)` &mdash; режим может быть:
	* 0 (выключен);
	* 1 (включен);
* `VOID FOG_COLOR(NUMBER r, NUMBER g, NUMBER b)`;
* `VOID FOG_DEPTH(NUMBER depth)` &mdash; задаёт дистанцию, на которой плотность
тумана будет максимальной;
* `NUMBER LOAD_OBJECT(ARRAY filename)`;
* `VOID POSITION_OBJECT(NUMBER object_id, NUMBER x, NUMBER y, NUMBER z)`;
* `VOID ROTATION_OBJECT(NUMBER object_id, NUMBER x, NUMBER y, NUMBER z)`;
* `VOID SCALE_OBJECT(NUMBER object_id, NUMBER x, NUMBER y, NUMBER z)`;
* `VOID PLAY_OBJECT(NUMBER object_id, NUMBER start_frame, NUMBER end_frame,
NUMBER loop)` &mdash; параметр loop может быть:
	* 0 (не зацикливать анимацию);
	* 1 (зацикливать анимацию);
* `VOID STOP_OBJECT(NUMBER object_id)` &mdash; ставит проигрывание анимации на
паузу;
* `NUMBER KEYSTATE(NUMBER key_code)` &mdash; возвращает состояние клавиши
клавиатуры с кодом `key_code` (список кодов клавиш см. ниже); состояние клавиши
может быть:
	* 0 (клавиша не нажата);
	* 1 (клавиша нажата);
* `NUMBER MOUSECLICK(VOID)` &mdash; возвращает дизьюнктивное объединение флагов
нажатых кнопок мыши; флаги кнопок мыши:
	* 1 &mdash; левая кнопка мыши;
	* 2 &mdash; средняя кнопка мыши;
	* 4 &mdash; правая кнопка мыши;
* `NUMBER MOUSEX(VOID)`;
* `NUMBER MOUSEY(VOID)`;
* `VOID POSITION_MOUSE(NUMBER x, NUMBER y)`;
* `VOID SYNC(VOID)` &mdash; вызывает очистку экрана, отрисовку всех объектов и
обновление окна (смену буферов).

#### Модуль Sound

* `NUMBER LOAD_SOUND(ARRAY filename)` &mdash; монофонический звук будет загружен
как 2D-звук, стереофонический звук &mdash; как 3D-звук;
* `VOID PLAY_SOUND(NUMBER sound_id, NUMBER loop)` &mdash; параметр loop может
быть:
	* 0 (не зацикливать воспроизведение);
	* 1 (зацикливать воспроизведение);
* `VOID STOP_SOUND(NUMBER sound_id)` &mdash; останавливает воспроизведение;
* `VOID POSITION_SOUND(NUMBER sound_id, NUMBER x, NUMBER y, NUMBER z)`;
* `VOID POSITION_LISTENER(NUMBER x, NUMBER y, NUMBER z)`;
* `VOID ROTATION_LISTENER(NUMBER x, NUMBER y, NUMBER z)`.

#### Коды клавиш

Клавиша | Код
--- | ---
ESCAPE | 1
F1 | 2
F2 | 3
F3 | 4
F4 | 5
F5 | 6
F6 | 7
F7 | 8
F8 | 9
F9 | 10
F10 | 11
F11 | 12
F12 | 13
PRINT SCREEN | 14
SCROLL LOCK | 15
PAUSE | 16
TILDE | 17
1 | 18
2 | 19
3 | 20
4 | 21
5 | 22
6 | 23
7 | 24
8 | 25
9 | 26
0 | 27
MINUS | 28
EQUAL | 29
BACKSPACE | 30
TAB | 31
CAPS LOCK | 32
SHIFT | 33
CONTROL | 34
META LEFT | 35
META RIGHT | 36
ALT | 37
SPACE | 38
MENU | 39
ENTER | 40
A | 41
B | 42
C | 43
D | 44
E | 45
F | 46
G | 47
H | 48
I | 49
J | 50
K | 51
L | 52
M | 53
N | 54
O | 55
P | 56
Q | 57
R | 58
S | 59
T | 60
U | 61
V | 62
W | 63
X | 64
Y | 65
Z | 66
BRACKET RIGHT | 67
BRACKET LEFT | 68
BACKSLASH | 69
SEMICOLON | 70
APOSTROPHE | 71
COMMA | 72
DOT | 73
SLASH | 74
INSERT | 75
DELETE | 76
HOME | 77
END | 78
PAGE UP | 79
PAGE DOWN | 80
UP | 81
LEFT | 82
DOWN | 83
RIGHT | 84
NUM LOCK | 85
NUM DIVIDE | 86
NUM MULTIPLY | 87
NUM SUBTRACT | 88
NUM ADD | 89
NUM DECIMAL | 90
NUM 0 | 91
NUM 1 | 92
NUM 2 | 93
NUM 3 | 94
NUM 4 | 95
NUM 5 | 96
NUM SPECIAL | 97
NUM 6 | 98
NUM 7 | 99
NUM 8 | 100
NUM 9 | 101
