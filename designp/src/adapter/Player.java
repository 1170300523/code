package adapter;

public class Player {
    CD targetCd;
    public void playCD(CD Cd){
        targetCd = Cd;
        targetCd.play();
    }

    public static void main(String[] args) {
        CD1 cd1 = new CD1();
        CD2 cd2 = new CD2();
        Player player = new Player();
        player.playCD(new CD1());
        player.playCD(cd2);
        player.playCD(new CD1());
    }
}
