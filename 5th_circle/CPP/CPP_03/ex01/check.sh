#!/bin/bash

outfile='my_ans.txt'

./ex01 >> my_ans.txt
diff ${outfile} ans.txt

rm ${outfile}