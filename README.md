# meta-c-language
---
## metaverse C programming lessons collection
---
develop in VS2019 Community

language  : c

---
## main module.c
---
1. main
- choose between example and homework

---
### call_homework.c
---
1. call_work
- show exists date list 
- choose date

---
### call_example.c
---
1. call_exam
- show exists example list
- choose example

---
### homework01.c
---
1. homeworkXX
- show the relevant dates function
- choose homework & execute function

---
### exam_XXXX.c
---
1. show example list
- if only one function exists, execute that funtcion

---
### Notification
---
1. in debug mode, function pointer error has occurred
- accese violation
- unknown reason, randomly occurrence
- x64 & x86 doesn't matter
- but sometimes it works if change solution platform x64 or x86 doesn't work
#### call_homework.c problem part
```c
	for (int i = 0; i <= fp_arraySize; i++) // search choosen date homework list
	{
		if (i == whatDate)
		{
			workDate[whatDate - 1](); // <- problem part
		}
  }
```
2. release flie working fine (.exe)