#!/bin/bash

#set_va
text_var="./for_test/test0"
replaced_word_var="="
new_word_var="->"

#set_outfile
out_ex04="${text_var}.replace"
out_sed="${text_var}.replace_sed"

./ex04 ${text_var} ${replaced_word_var} ${new_word_var}
cat ${text_var} | sed "s/${replaced_word_var}/${new_word_var}/g" > ${out_sed}


diff ${out_ex04} ${out_sed}
if [ $? -eq 0 ] ; then
	echo "ok"
else
	echo "ng"
fi

#rm ${out_ex04} ${out_sed}