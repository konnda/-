#include<stdio.h>

#define STACK_SIZE  100   /* スタックに積むことのできるデータの最大個数 */
#define SUCCESS     1     /* 成功 */
#define FAILURE     0     /* 失敗 */

typedef int data_t;       /* スタックに貯えるデータの型 */

data_t stack_data[STACK_SIZE];  /* スタック本体 */
int stack_num;

int push(data_t push_data)
{
    if (stack_num < STACK_SIZE) {
        stack_data[stack_num] = push_data;
        stack_num ++;
        return SUCCESS;
    } else {
        return FAILURE;
    }
}

int pop(data_t *pop_data)
{
    if(stack_num > 0){
        int o;
        o = stack_num;
        printf("pop %d\n",stack_data[o - 1]);
        stack_num--;
        *pop_data = stack_data[stack_num];
        return SUCCESS;
    }else{
        return FAILURE;
    }
}

void stackPrint(){
    int i;

    printf("stack[");
    for(i = 0;i < stack_num; i++){
        printf("%3d", stack_data[i]);
    }
    printf("]\n");
}

int peek(data_t *peek_data){
    if(stack_num > 0){
        printf("peek %d\n", stack_data[stack_num - 1]);
        *peek_data = stack_data[stack_num];
        return SUCCESS;
    }else{
        return FAILURE;
    }
}

int size(data_t *size_data){
    int stack_data_size = sizeof stack_data / sizeof stack_data[0];
    
    printf("overall memoly size:%d\n", sizeof stack_data);
    printf("one element memoly size:%d\n", sizeof stack_data[0]);
    printf("element count:%d\n", stack_data_size);
}

int main()
{
    int i,p,b;/*iは数字入力用、bは呼び出す関数選ぶ用*/

    stack_num = 0;
    for(;;)
    {
        printf("0 = push 1 = pop -1 = end\n");
        scanf("%d",&b);
        if(b == 0)/*push*/
        {
            for(;;)
            {
                printf("push number:");
                scanf("%d", &i);

                if(i == -1) 
                {
                    break;
                }else{
                    push(i);
                    printf("push %2d\n", i);
                    stackPrint();
                }
            }  
        }

        if(b == 1) /*pop*/
        {
            pop(&p);
            stackPrint();
        }

        if(b == 2)
        {
            peek(&p);
        }

        if(b == 3)
        {
            size(&p);
        }

        if(b == -1)
        {
            return 0;
        }
    }
}