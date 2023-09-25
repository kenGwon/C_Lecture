


#if 1 // 비트 시프트 연산 대신에 공용체(union) 써보기 !!

#include <stdio.h>

int main(void)
{
    union 
    {                       // 현재 공용체로 선언되어 있기 때문에 그들의 멤버인 BYTE와 s는
        unsigned char BYTE; // BYTE가 1000번지라면
        struct              // 이 줄의 struct s도 1000번지에 위치한다.
        {
            unsigned b0: 1; // 1 bit;
            unsigned b1: 1; // 1 bit;
            unsigned b2: 1; // 1 bit;
            unsigned b3: 1; // 1 bit;
            unsigned lownibble: 4; // 4 bit;
        } s;
    } u;
    
    u.BYTE = 0xff;
    printf("u.BYTE: %0x\n", u.BYTE);
    u.s.b3 = 0;
    printf("u.BYTE: %0x\n", u.BYTE);
          
    return 0;
}

#endif

#if 0 // 진짜 제대로 된 비트 시프트 연산을 써본 사례 !!

#include <stdio.h>


int main(void)
{
    unsigned char BYTE = 0xff; 

    printf("%0x\n", BYTE); // 0b 1111 1111
    
    // 3번 비트를 reset하는 기능
    // 1번비트를 왼쪽으로 3번 밀어서 거기를 플립해준다. // 결과: 0b 1111 1011
    BYTE &= ~(1 << 3); // 1) (1): 1   2) (1 << 3): 1000   3) ~(1 << 3): 0111
                       // 4) BYTE = BYTE & ~(1 << 3); : 1111 1011
    
    printf("%0x\n", BYTE); // 0b 1111 1011 = 0xf7
          
    return 0;
}

#endif