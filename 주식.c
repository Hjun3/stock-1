#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void stock();
int stock_type();
int buy();
int sell();
int random_low();
int random_mid();
int random_high();


int main(void) {
    srand(time(NULL));
    stock();

    return 0;
}

void stock() {
    char choice[100];
    int value = 10000;
    int stock_choice;
    int money = 500000;
    int* num_stock = NULL;

    stock_choice = stock_type();

    do {
        printf("\n현재 주가");
        if (stock_choice == 1) {
            printf("(삼성/위험도:*)");
        }
        else if (stock_choice == 2) {
            printf("(애플/위험도:**)");
        }
        else if (stock_choice == 3) {
            printf("(코인/위험도:***)");
        }
        printf(" : %d\n현재 자본 : %d\n현재 주식 개수 : %d\n\n", value, money, num_stock);
        printf("매도하시겠습니까? 매입하시겠습니까? (매도/매입/종료)\n>> ");
        gets(choice);
        if (strcmp(choice, "매도") == 0) {
            if (num_stock <= 0) {
                printf("매도할 주식이 없습니다.\n");
            }
            else money = sell(value, money, &num_stock);
        }
        else if (strcmp(choice, "매입") == 0) {
            money = buy(value, money, &num_stock);

        }
        if (stock_choice == 1) {
            value = random_low(value);
        }
        else if (stock_choice == 2) {
            value = random_mid(value);
        }
        else if (stock_choice == 3) {
            value = random_high(value);
        }

    } while (strcmp(choice, "종료") != 0);


}

int stock_type() {
    char stk_choice[100];
    printf("주식을 선택해주세요.\n");
    printf("삼성 (위험도: *  )\n애플 (위험도: ** )\n코인 (위험도: ***)\n (삼성/애플/코인)\n>> ");
    gets(stk_choice, 100);

    if (strcmp(stk_choice, "삼성") == 0) {
        return 1;
    }
    else if (strcmp(stk_choice, "애플") == 0) {
        return 2;
    }
    else if (strcmp(stk_choice, "코인") == 0) {
        return 3;
    }

}
int buy(int value_buy, int money_buy, int* num_stk) {
    int num = 0;

    printf("\n몇 주를 구매하시겠습니까? \n현재 주가 : %d 현재 자본 : %d \n>> ", value_buy, money_buy);
    scanf("%d", &num);
    getchar();
    if (money_buy < num * value_buy) {
        printf("매입할 돈이 없습니다. \n");
        return money_buy;
    }
    else {
        money_buy -= num * value_buy;
        *num_stk += num;
        return money_buy;
    }

}

int sell(int value_sell, int money_sell, int* num_stk) {
    int num = 0;
    printf("\n몇 주를 판매하시겠습니까? \n현재 주가 : %d 현재 자본 : %d \n>>", value_sell, money_sell);
    scanf("%d", &num);
    getchar();
    money_sell += num * value_sell;
    *num_stk -= num;

    return money_sell;

}

int random_low(int ch_value) {
    int change, sign;
    change = rand() % 50 + 31;
    sign = rand() % 2;

    if (sign == 0) {
        ch_value -= change;
    }
    else if (sign == 1) {
        ch_value += change;
    }
    return ch_value;
}

int random_mid(int ch_value) {
    int change, sign;
    change = rand() % 100 + 101;
    sign = rand() % 2;

    if (sign == 0) {
        ch_value -= change;
    }
    else if (sign == 1) {
        ch_value += change;
    }
    return ch_value;
}
int random_high(int ch_value) {
    int change, sign;
    change = rand() % 1000 + 1001;
    sign = rand() % 2;

    if (sign == 0) {
        ch_value -= change;
    }
    else if (sign == 1) {
        ch_value += change;
    }
    return ch_value;
}



