# Language Checker

### Problem

You work for a publisher of technical journals.

You are getting lots of submissions in plain ASCII text from non-native English  speakers , and though the content is great, the spelling is sometimes terrible, and you’d like some way of automatically checking the quality before the stuff goes through to your editors. You want to pass each submission through a program that will tell us how many errors there are, and print them out in context. You also want to be able to have multiple special dictionaries for each journal that contain words that are commonly used technically in those journals, but which might not appear in a standard English dictionary.


You need to produce a console program, who’s command line looks something like this:

`scheck [-n] [[-d special.dict] …] [file …]`

`-n` : prints the number of errors

`-d` : specifies a special dictionary. There can be more than one -d option.


The checker checks the listed files (if none are specified it reads standard input) and produces output of the form:

`article1.txt,2 errors

article1.text,7,thre,perhaps thre is a reaction

article1.text,12,phiton,low-energy phiton is emitted`


Your may also need XML output later on, but you should get the CSV format above working first. There were a lot of submissions, and checking a document should not take more than two or three times as long as listing it on the screen would do.



### Directory Structure

`scheck`
`|--> bin`
`|--> data`
`|--> doc`
`|--> inc`
`|--> src`
`|--> tests`



* bin : checker executables are stored here
* data : supporting data (like dictionaries) is stored here
* doc : documentation
* inc : C++ header files go here
* src : C++ source files go here
* tests : tests to check the working of app are stored here
