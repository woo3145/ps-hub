class Solution {
    public int solution(int[] bandage, int health, int[][] attacks) {
        int attacksCount = 0;
        int attacksTurn = attacks[attacksCount][0];
        int bonus = 0;
        int healthMax = health;
        for(int i = 0 ; i <= attacks[attacks.length-1][0] ; i++) {
            if (i == attacksTurn) {
                health -= attacks[attacksCount][1];
                if (health <= 0) {return -1;}
                else{
                    bonus = 0;
                    if (attacksCount < attacks.length-1) {
                        attacksTurn = attacks[++attacksCount][0];
                    }
                }
            }
            else {
                bonus++;
                if (bonus == bandage[0]) {
                    if (health < healthMax-bandage[2]) { health += bandage[2]; }
                    else { health = healthMax; }
                    bonus = 0;
                }
                if (health < healthMax-bandage[1]) {
                    health += bandage[1];
                }
                else { health = healthMax;
                }
            }
        }
        return health;
    }
}