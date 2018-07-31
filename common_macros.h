
#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_


#define SET_BIT(REG,BIT) (REG|=(1<<BIT))
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))


#define ROR(REG,num) ( REG= (REG>>num) | (REG<<(8-num)) )
#define ROL(REG,num) ( REG= (REG<<num) | (REG>>(8-num)) )



#endif
