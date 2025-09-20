#!/bin/bash

outfile='my_ans.txt'

./ex00 >> my_ans.txt
diff ${outfile} ans.txt

rm ${outfile}