// we will use bit masking teechnique.
class Solution {
    public int maximumGood(int[][] statements) {
        int n=statements.length;
        int maxgudper=0;
        int combi=1<<n;
        int [] roles=new int[n];
        //iterate krege sare combinations me gud aur bad using bit masks.
        for(int mask=1;mask<combi;mask++){
            int currentgudper=apply(roles,mask);//Represents a function that accepts one argument and produces a result. This is a functional interface whose functional method is apply(Object) .**helper mrthod applying  this masl into a form of array.
            if(valid(statements,roles))
             maxgudper=Math.max(maxgudper,currentgudper);

        }
        return maxgudper;
        
    }
    //convert bitmask to role array,count good people in this  mask
    private int apply(int[] roles,int mask){
        //3->0 1 1
        int count =0;
        int n=roles.length;
        for(int i=0;i<n;i++){
            count+=roles[i]=mask&1;
            mask>>=1;
        }
        return count;
    }
    private boolean valid(int[][] statements,int[] roles){
        int n=statements.length;
        for(int i=0;i<n;i++){
            //ignore bad pupil
            if(roles[i]==0) continue;
            //only check gud pupil
            for(int j=0;j<n;j++){
                if(statements[i][j]==2) continue;
                //statements of a gud person contradicts the assigned role in this combination
                if(statements[i][j]!=roles[j]) return false;
            }
        }
        return true;
    }

}
