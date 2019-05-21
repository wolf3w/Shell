# Shell

Еще одна оболочка. Была создана при изучении Makefile и Git.

## Установка

Перейти в директорию с Makefile и в консоли набрать:
```bash
make
```
После запускать командой:
```bash
./binary
```

## Команды

Каждой команде соответствует заголовочный и исходный файлы.

**help** ([help.c](https://github.com/wolf3w/Shell/blob/master/source/help.c)) - выводит все команды
**cd** ([cd.c](https://github.com/wolf3w/Shell/blob/master/source/cd.c)) - меняет текущую директорию. Аналог cd из UNIX.
**cp** ([cp.c](https://github.com/wolf3w/Shell/blob/master/source/cp.c)) - копирует файл. После нужно ввести имя копируемого файла
**df** ([df.c](https://github.com/wolf3w/Shell/blob/master/source/df.c)) - удаляет файл (но не директорию)
**ls** ([ls.c](https://github.com/wolf3w/Shell/blob/master/source/ls.c)) - выводит все файлы в директории
**md** ([md.c](https://github.com/wolf3w/Shell/blob/master/source/md.c)) - создает директорию
**rd** ([rd.c](https://github.com/wolf3w/Shell/blob/master/source/rd.c)) - удаляет директорию
**rf** ([rf.c](https://github.com/wolf3w/Shell/blob/master/source/rf.c)) - переименовывает файл
