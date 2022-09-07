#ifndef USERMANUAL_H_
#define USERMANUAL_H_

typedef struct {
	void (*print)(void);
}UserManual;

UserManual *getUserManual(void);

#endif
