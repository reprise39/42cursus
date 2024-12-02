#!/bin/bash
make
cc test.c libftprintf.a -L. -lftprintf