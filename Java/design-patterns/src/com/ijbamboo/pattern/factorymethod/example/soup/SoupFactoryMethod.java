package com.ijbamboo.pattern.factorymethod.example.soup;

import com.ijbamboo.pattern.soup.ChickenSoup;
import com.ijbamboo.pattern.soup.ClamChowder;
import com.ijbamboo.pattern.soup.FishChowder;
import com.ijbamboo.pattern.soup.Minnestrone;
import com.ijbamboo.pattern.soup.PastaFazul;
import com.ijbamboo.pattern.soup.TofuSoup;
import com.ijbamboo.pattern.soup.VegetableSoup;

/**
 * @author ����
 * @Description 
 * @version 1.0
 * 2018��2��3�� ����5:25:57
 */
public class SoupFactoryMethod {
    public SoupFactoryMethod() {}
        
    public SoupBuffet makeSoupBuffet() {
        return new SoupBuffet();
    }


    public ChickenSoup makeChickenSoup() {
        return new ChickenSoup();
    }
    public ClamChowder makeClamChowder() {
        return new ClamChowder();
    }
    public FishChowder makeFishChowder() {
        return new FishChowder();
    }
    public Minnestrone makeMinnestrone() {
        return new Minnestrone();
    }
    public PastaFazul makePastaFazul() {
        return new PastaFazul();
    }
    public TofuSoup makeTofuSoup() {
        return new TofuSoup();
    }
    public VegetableSoup makeVegetableSoup() {
        return new VegetableSoup();
    }


    public String makeBuffetName() {
        return "Soup Buffet";
    }
}