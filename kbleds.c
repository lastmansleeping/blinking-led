#include <linux/module.h>
#include <linux/configfs.h>
#include <linux/init.h>
#include <linux/tty.h>          /* For fg_console, MAX_NR_CONSOLES */
#include <linux/kd.h>           /* For KDSETLED */
#include <linux/vt.h>
#include <linux/console_struct.h>       /* For vc_cons */
#include <linux/vt_kern.h>
MODULE_DESCRIPTION("Example module illustrating the use of Keyboard LEDs.");
MODULE_LICENSE("GPL");
struct timer_list my_timer;
struct tty_driver *my_driver;
char kbledstatus = 0;

static int a[15];
//static int arr_argc = 0;
//module_param_array(a, int,&arr_argc, 0);
//MODULE_PARM_DESC(a,"this is the array variable");

static char *c = "THIS IS OS LAB :D";
module_param(c, charp, 0);
MODULE_PARM_DESC(c,"this is the character string variable");
int j=0;

#define BLINK_DELAY   HZ/2//SETTING FREQUENCY OF LEDS TO 1/2 HZ
			//i.e.,THE LED FUNCTION IS CALLED EVERY 1/2 SECOND
#define ALL_LEDS_ON   0x07//ON
#define RESTORE_LEDS  0xFF//OFF
/*
 * Function my_timer_func blinks the keyboard LEDs periodically by invoking
 * command KDSETLED of ioctl() on the keyboard drive.
 * The argument to KDSETLED is alternatively set to 7 (thus causing the led
 * mode to be set to LED_SHOW_IOCTL, and all the leds are lit) and to 0xFF
 * (any value above 7 switches back the led mode to LED_SHOW_FLAGS, thus
 * the LEDs reflect the actual keyboard status).
 *     /usr/src/linux/drivers/char/keyboard.c, function setledstate().
 *
 */
static void my_timer_func(unsigned long ptr)
{
        int *pstatus = (int *)ptr;
	if(j<20)
	{
        	//if (*pstatus == ALL_LEDS_ON)
	
		if(a[j]==0)
        	        *pstatus = RESTORE_LEDS;	
       		else
        	        *pstatus = ALL_LEDS_ON;
		j=(j+1);
	}
	
	else
		*pstatus = RESTORE_LEDS;

	//CODE THAT IS USED TO SET THE LEDS TO THE DESIRED pstatus
        (my_driver->ops->ioctl) (vc_cons[fg_console].d->port.tty, KDSETLED,*pstatus);
        my_timer.expires = jiffies + BLINK_DELAY;
        add_timer(&my_timer);
}
static int __init kbleds_init(void)
{
        int i;
	if(c[0]=='a' || c[0]=='A')
	{	
		a[0]=1;
		a[1]=0;
		a[2]=1;
		a[3]=1;
		a[4]=1;
		a[5]=0;
		a[6]=0;
		a[7]=0;
		a[8]=0;
		a[9]=0;
		a[10]=0;
		a[11]=0;
		a[12]=0;
		a[13]=0;
		a[14]=0;
	}	
	if(c[0]=='b' || c[0]=='B')
	{	
		a[0]=1;
		a[1]=1;
		a[2]=1;
		a[3]=0;
		a[4]=1;
		a[5]=0;
		a[6]=1;
		a[7]=0;
		a[8]=1;
		a[9]=0;
		a[10]=0;
		a[11]=0;
		a[12]=0;
		a[13]=0;
		a[14]=0;
	}
	if(c[0]=='c' || c[0]=='C')
	{	
		a[0]=1;
		a[1]=1;
		a[2]=1;
		a[3]=0;
		a[4]=1;
		a[5]=0;
		a[6]=1;
		a[7]=1;
		a[8]=1;
		a[9]=0;
		a[10]=1;
		a[11]=0;
		a[12]=0;
		a[13]=0;
		a[14]=0;
	}
	if(c[0]=='d' || c[0]=='D')
	{	
		a[0]=1;
		a[1]=1;
		a[2]=1;
		a[3]=0;
		a[4]=1;
		a[5]=0;
		a[6]=1;
		a[7]=0;
		a[8]=0;
		a[9]=0;
		a[10]=0;
		a[11]=0;
		a[12]=0;
		a[13]=0;
		a[14]=0;
	}
	if(c[0]=='e' || c[0]=='E')
	{	
		a[0]=1;
		a[1]=0;
		a[2]=0;
		a[3]=0;
		a[4]=0;
		a[5]=0;
		a[6]=0;
		a[7]=0;
		a[8]=0;
		a[9]=0;
		a[10]=0;
		a[11]=0;
		a[12]=0;
		a[13]=0;
		a[14]=0;
	}
	if(c[0]=='f' || c[0]=='F')
	{	
		a[0]=1;
		a[1]=0;
		a[2]=1;
		a[3]=0;
		a[4]=01;
		a[5]=01;
		a[6]=01;
		a[7]=0;
		a[8]=01;
		a[9]=0;
		a[10]=0;
		a[11]=0;
		a[12]=0;
		a[13]=0;
		a[14]=0;
	}
	if(c[0]=='g' || c[0]=='G')
	{	
		a[0]=01;
		a[1]=01;
		a[2]=01;
		a[3]=0;
		a[4]=01;
		a[5]=01;
		a[6]=01;
		a[7]=0;
		a[8]=01;
		a[9]=0;
		a[10]=0;
		a[11]=0;
		a[12]=0;
		a[13]=0;
		a[14]=0;
	}
	if(c[0]=='h' || c[0]=='H')
	{	
		a[0]=01;
		a[1]=0;
		a[2]=01;
		a[3]=0;
		a[4]=01;
		a[5]=0;
		a[6]=01;
		a[7]=0;
		a[8]=0;
		a[9]=0;
		a[10]=0;
		a[11]=0;
		a[12]=0;
		a[13]=0;
		a[14]=0;
	}
	if(c[0]=='i' || c[0]=='I')
	{	
		a[0]=1;
		a[1]=0;
		a[2]=01;
		a[3]=0;
		a[4]=0;
		a[5]=0;
		a[6]=0;
		a[7]=0;
		a[8]=0;
		a[9]=0;
		a[10]=0;
		a[11]=0;
		a[12]=0;
		a[13]=0;
		a[14]=0;
	}
	if(c[0]=='j' || c[0]=='J')
	{	
		a[0]=01;
		a[1]=0;
		a[2]=01;
		a[3]=01;
		a[4]=01;
		a[5]=0;
		a[6]=01;
		a[7]=01;
		a[8]=01;
		a[9]=0;
		a[10]=01;
		a[11]=01;
		a[12]=01;
		a[13]=0;
		a[14]=0;
	}
	if(c[0]=='k' || c[0]=='K')
	{	
		a[0]=1;
		a[1]=01;
		a[2]=01;
		a[3]=0;
		a[4]=01;
		a[5]=0;
		a[6]=01;
		a[7]=01;
		a[8]=01;
		a[9]=0;
		a[10]=0;
		a[11]=0;
		a[12]=0;
		a[13]=0;
		a[14]=0;
	}
	if(c[0]=='l' || c[0]=='L')
	{	
		a[0]=01;
		a[1]=0;
		a[2]=01;
		a[3]=01;
		a[4]=01;
		a[5]=0;
		a[6]=01;
		a[7]=0;
		a[8]=01;
		a[9]=0;
		a[10]=0;
		a[11]=0;
		a[12]=0;
		a[13]=0;
		a[14]=0;
	}
	if(c[0]=='m' || c[0]=='M')
	{	
		a[0]=01;
		a[1]=01;
		a[2]=01;
		a[3]=0;
		a[4]=01;
		a[5]=01;
		a[6]=01;
		a[7]=0;
		a[8]=0;
		a[9]=0;
		a[10]=0;
		a[11]=0;
		a[12]=0;
		a[13]=0;
		a[14]=0;
	}
	if(c[0]=='n' || c[0]=='N')
	{	
		a[0]=01;
		a[1]=01;
		a[2]=01;
		a[3]=0;
		a[4]=01;
		a[5]=0;
		a[6]=0;
		a[7]=0;
		a[8]=0;
		a[9]=0;
		a[10]=0;
		a[11]=0;
		a[12]=0;
		a[13]=0;
		a[14]=0;
	}
	if(c[0]=='o' || c[0]=='O')
	{	
		a[0]=01;
		a[1]=01;
		a[2]=01;
		a[3]=0;
		a[4]=01;
		a[5]=01;
		a[6]=01;
		a[7]=0;
		a[8]=01;
		a[9]=01;
		a[10]=01;
		a[11]=0;
		a[12]=0;
		a[13]=0;
		a[14]=0;
	}
	if(c[0]=='p' || c[0]=='P')
	{	
		a[0]=01;
		a[1]=0;
		a[2]=01;
		a[3]=01;
		a[4]=01;
		a[5]=0;
		a[6]=01;
		a[7]=01;
		a[8]=01;
		a[9]=0;
		a[10]=01;
		a[11]=0;
		a[12]=0;
		a[13]=0;
		a[14]=0;
	}
	if(c[0]=='q' || c[0]=='Q')
	{	
		a[0]=1;
		a[1]=1;
		a[2]=1;
		a[3]=0;
		a[4]=1;
		a[5]=1;
		a[6]=01;
		a[7]=0;
		a[8]=01;
		a[9]=0;
		a[10]=01;
		a[11]=01;
		a[12]=01;
		a[13]=0;
		a[14]=0;
	}
	if(c[0]=='r' || c[0]=='R')
	{	
		a[0]=01;
		a[1]=0;
		a[2]=01;
		a[3]=01;
		a[4]=01;
		a[5]=0;
		a[6]=01;
		a[7]=0;
		a[8]=0;
		a[9]=0;
		a[10]=0;
		a[11]=0;
		a[12]=0;
		a[13]=0;
		a[14]=0;
	}
	if(c[0]=='s' || c[0]=='S')
	{	
		a[0]=01;
		a[1]=0;
		a[2]=01;
		a[3]=0;
		a[4]=01;
		a[5]=0;
		a[6]=0;
		a[7]=0;
		a[8]=0;
		a[9]=0;
		a[10]=0;
		a[11]=0;
		a[12]=0;
		a[13]=0;
		a[14]=0;
	}
	if(c[0]=='t' || c[0]=='T')
	{	
		a[0]=01;
		a[1]=01;
		a[2]=01;
		a[3]=0;
		a[4]=0;
		a[5]=0;
		a[6]=0;
		a[7]=0;
		a[8]=0;
		a[9]=0;
		a[10]=0;
		a[11]=0;
		a[12]=0;
		a[13]=0;
		a[14]=0;
	}
	if(c[0]=='u' || c[0]=='U')
	{	
		a[0]=01;
		a[1]=0;
		a[2]=01;
		a[3]=0;
		a[4]=01;
		a[5]=01;
		a[6]=01;
		a[7]=0;
		a[8]=0;
		a[9]=0;
		a[10]=0;
		a[11]=0;
		a[12]=0;
		a[13]=0;
		a[14]=0;
	}
	if(c[0]=='v' || c[0]=='V')
	{	
		a[0]=01;
		a[1]=0;
		a[2]=01;
		a[3]=0;
		a[4]=01;
		a[5]=0;
		a[6]=01;
		a[7]=01;
		a[8]=01;
		a[9]=0;
		a[10]=0;
		a[11]=0;
		a[12]=0;
		a[13]=0;
		a[14]=0;
	}
	if(c[0]=='w' || c[0]=='W')
	{	
		a[0]=01;
		a[1]=0;
		a[2]=01;
		a[3]=01;
		a[4]=01;
		a[5]=0;
		a[6]=01;
		a[7]=01;
		a[8]=01;
		a[9]=0;
		a[10]=0;
		a[11]=0;
		a[12]=0;
		a[13]=0;
		a[14]=0;
	}
	if(c[0]=='x' || c[0]=='X')
	{	
		a[0]=01;
		a[1]=01;
		a[2]=01;
		a[3]=0;
		a[4]=01;
		a[5]=0;
		a[6]=01;
		a[7]=0;
		a[8]=01;
		a[9]=01;
		a[10]=01;
		a[11]=0;
		a[12]=0;
		a[13]=0;
		a[14]=0;
	}
	if(c[0]=='y' || c[0]=='Y')
	{	
		a[0]=01;
		a[1]=01;
		a[2]=01;
		a[3]=0;
		a[4]=01;
		a[5]=0;
		a[6]=01;
		a[7]=01;
		a[8]=01;
		a[9]=0;
		a[10]=01;
		a[11]=01;
		a[12]=01;
		a[13]=0;
		a[14]=0;
	}
	if(c[0]=='z' || c[0]=='Z')
	{	
		a[0]=01;
		a[1]=01;
		a[2]=01;
		a[3]=0;
		a[4]=01;
		a[5]=01;
		a[6]=01;
		a[7]=0;
		a[8]=01;
		a[9]=0;
		a[10]=01;
		a[11]=0;
		a[12]=0;
		a[13]=0;
		a[14]=0;
	}

        printk(KERN_INFO "kbleds: loading\n");
        printk(KERN_INFO "kbleds: fgconsole is %x\n", fg_console);
        for (i = 0; i < MAX_NR_CONSOLES; i++) {
                if (!vc_cons[i].d)
                        break;
                printk(KERN_INFO "poet_atkm: console[%i/%i] #%i, tty %lx\n", i,
                       MAX_NR_CONSOLES, vc_cons[i].d->vc_num,
                       (unsigned long)vc_cons[i].d->port.tty);
        }
        printk(KERN_INFO "kbleds: finished scanning consoles\n");
        my_driver = vc_cons[fg_console].d->port.tty->driver;
        printk(KERN_INFO "kbleds: tty driver magic %x\n", my_driver->magic);
        /*
         * Set up the LED blink timer the first time
         */
        init_timer(&my_timer);
        my_timer.function = my_timer_func;
        my_timer.data = (unsigned long)&kbledstatus;
        my_timer.expires = jiffies + BLINK_DELAY;
        add_timer(&my_timer);
        return 0;
}
static void __exit kbleds_cleanup(void)
{
        printk(KERN_INFO "kbleds: unloading...\n");
        del_timer(&my_timer);
        (my_driver->ops->ioctl) (vc_cons[fg_console].d->port.tty, KDSETLED,
                            RESTORE_LEDS);
}
module_init(kbleds_init);
module_exit(kbleds_cleanup);

