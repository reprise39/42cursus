#!/bin/bash

outfile='my_ans.txt'

./ex02 >> my_ans.txt
diff ${outfile} ans.txt

rm ${outfile}