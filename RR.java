import java.util.*;
class RRDynamic{
	int[] pro,arr,rem,wai,ta,cp;
	int size,q,time=0,flag=0;
	RRDynamic(int size){
		this.size=size;
		pro=new int[size];
		wai=new int[size];
		ta=new int[size];
		rem=new int[size];
		arr=new int[size];
		cp=new int[size];
	}
	void get(){
	
		Scanner sc=new Scanner(System.in);
	
		for(int i=0;i<size;++i){
			System.out.print("Enter process time P"+(i+1)+":");
			rem[i]=pro[i]=sc.nextInt();
			System.out.print("Enter arrival time P"+(i+1)+":");
			arr[i]=sc.nextInt();
		}
		System.out.print("Enter quantum time :");
		q=sc.nextInt();
	}
	void round(){
		int it=0,j=0;
		float t=0.0f,b=0.0f;
		time=arr[0];
		do{
			j=0;
			flag=0;
			for(int i=0;i<size;i++){
				if((arr[i]<=time)&&(rem[i]>0)){
					System.out.print("P"+(i+1)+"\t");
					flag=1;
					time=time+q;
					if(rem[i]<q)
						time=time-(q-rem[i]);
					
					rem[i]=rem[i]-q;
					cp[i]=time;
				}
			}
			if(flag==0){
				it=it+1;
				time=time+1;
			}
			for(int i=0;i<size;i++)
				if(rem[i]>0)
					j=1;
		}while(j==1);
		
		float thru=(float)size/time;
		System.out.println("\nThroughput :" +thru);
		System.out.println("Utilisation :"+((time-it)/time)*100);
		
		System.out.println("\nPName\tArrival\tPTime\tCTime\tWaiting\tTurnAround");
		for(int i=0;i<size;i++){
			ta[i]=cp[i]-arr[i];
			wai[i]=ta[i]-pro[i];
			System.out.println("P"+(i+1)+"\t"+arr[i]+"\t"+pro[i]+"\t"+cp[i]+"\t"+wai[i]+"\t"+ta[i]);
			b+=wai[i];
			t+=ta[i];
		}
		System.out.println("Average Waiting Time:"+(b/size));
		System.out.println("Average Turnaround Time:"+(t/size));
	}
}
class RR{
	public static void main(String [] args){
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the number of Processes");
		int n =sc.nextInt();
		RRDynamic obj =new RRDynamic(n);
		obj.get();
		obj.round();
	}
}							