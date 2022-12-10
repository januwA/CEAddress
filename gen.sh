#!/bin/bash

win_flex.exe --wincompat -o ./CEAddress/src/lexer.cpp ./CEAddress/gen/lexer.l

win_bison.exe --no-line --defines=./CEAddress/src/parser.h -d -o ./CEAddress/src/parser.cpp ./CEAddress/gen/parser.y