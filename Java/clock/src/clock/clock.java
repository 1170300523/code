package clock;

import display.display;

public class clock {
	private display hour = new display(24);  //**private**����ֻ���ڳ�Ա�����ͳ�Ա����������  
	private display minutes = new display(60);
	
	public void start() {
		while(true) {
			minutes.increase();
			if(minutes.getvalue()==0)
				hour.increase();
			System.out.printf("%02d:%02d\n",hour.getvalue(),minutes.getvalue());
		}			
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		clock myClock = new clock();
		myClock.start();
		
	}

}
