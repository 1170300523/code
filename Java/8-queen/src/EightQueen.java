public class EightQueen {
    static int strategyOrder = 0;

    static boolean check(int row,int column, int[] queen){
        for(int i=0;i<row;i++){
            if(column == queen[i] || Math.abs(column - queen[i]) == row - i){
                return false;
            }
        }
        return true;
    }

    static void printQueen(int[] queen ){
        strategyOrder++;
//        System.out.printf("strategy "+strategyOrder+": ");
//        for(int i=0;i<queen.length;i++){
//            System.out.printf(queen[i]+" ");
//        }
//        System.out.println();
    }
   static void putQueen(int row, int[] queen){
        if(row == queen.length){
            strategyOrder++;
            return;
        }

        for(int i=0;i<queen.length;i++){
//            boolean flag = true;
//            for(int j=0;j<row;j++){
//                if(i == queen[j] || Math.abs(i - queen[j]) == row - j){
//                    flag = false;
//                    break;
//                }
//            }

            if(check(row,i,queen)){
                queen[row] = i;
                putQueen(row+1,queen);
            }
        }
    }

    static  void start(int queenNum){
            int[] queen = new int[queenNum];
            putQueen(0,queen);
    }


    public static void main(String[] args) {
        long start = System.currentTimeMillis();
        start(14);
        long end = System.currentTimeMillis();
        System.out.println(strategyOrder+":"+(end - start)+ "ms");
    }
}
