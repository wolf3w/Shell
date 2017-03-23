RAW_OBJ = main.o err1.o df.o md.o cp.o of.o rd.o rf.o stfile.o help.o
RAW_LIB = err1.h df.h md.h cp.h of.h rd.h rf.h stfile.h help.h
RAW_SRC	= main.c err1.c df.c md.c cp.c of.c rd.c rf.c stfile.c help.c

obj		= $(addprefix $(obj_dir),$(RAW_OBJ))
lib     = $(addprefix $(h_dir),$(RAW_LIB)) 
src		= $(addprefix $(src_dir),$(RAW_SRC)) 

obj_dir = ./objects/
h_dir   = ./headers/
src_dir = ./source/

#------------------- Executable ---------------

binary : $(obj)
	gcc -o binary $^

#------------------- Object files -------------

$(obj_dir)main.o   : $(src_dir)main.c   $(lib)
	gcc -o $@ -c $(src_dir)main.c
$(obj_dir)err1.o   : $(src_dir)err1.c   $(h_dir)err1.h
	gcc -o $@ -c $(src_dir)err1.c
$(obj_dir)df.o     : $(src_dir)df.c     $(h_dir)df.h
	gcc -o $@ -c $(src_dir)df.c
$(obj_dir)md.o     : $(src_dir)md.c     $(h_dir)md.h
	gcc -o $@ -c $(src_dir)md.c
$(obj_dir)cp.o     : $(src_dir)cp.c     $(h_dir)cp.h
	gcc -o $@ -c $(src_dir)cp.c
$(obj_dir)of.o     : $(src_dir)of.c     $(h_dir)of.h
	gcc -o $@ -c $(src_dir)of.c
$(obj_dir)rd.o     : $(src_dir)rd.c     $(h_dir)rd.h
	gcc -o $@ -c $(src_dir)rd.c
$(obj_dir)rf.o     : $(src_dir)rf.c     $(h_dir)rf.h
	gcc -o $@ -c $(src_dir)rf.c
$(obj_dir)stfile.o : $(src_dir)stfile.c $(h_dir)stfile.h
	gcc -o $@ -c $(src_dir)stfile.c
$(obj_dir)help.o   : $(src_dir)help.c   $(h_dir)help.h
	gcc -o $@ -c $(src_dir)help.c

#------------------- Special -------------------
clean :
	rm -f binary ./objects/$(OBJECTS)
test :
	$(obj)
#------- $(addprefix pref, arg) добавляет к arg префикс pref
