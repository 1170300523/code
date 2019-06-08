package com.ijbamboo.pattern.builder.example.soup;

import com.ijbamboo.pattern.soup.ChickenSoup;
import com.ijbamboo.pattern.soup.ClamChowder;
import com.ijbamboo.pattern.soup.FishChowder;
import com.ijbamboo.pattern.soup.Minnestrone;
import com.ijbamboo.pattern.soup.PastaFazul;
import com.ijbamboo.pattern.soup.TofuSoup;
import com.ijbamboo.pattern.soup.VegetableSoup;

/**
 * 自助汤建造器
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午3:36:51
 */
public abstract class SoupBuffetBuilder {
	SoupBuffet soupBuffet;
    
    public SoupBuffet getSoupBuffet() {
        return soupBuffet;
    }
    
    public void buildSoupBuffet() {
        soupBuffet = new SoupBuffet();
    }
    
    public abstract void setSoupBuffetName();
        
    public void buildChickenSoup() {
        soupBuffet.chickenSoup = new ChickenSoup();
    }
    public void buildClamChowder() {
        soupBuffet.clamChowder = new ClamChowder();
    }
    public void buildFishChowder() {
        soupBuffet.fishChowder = new FishChowder();
    }
    public void buildMinnestrone() {
        soupBuffet.minnestrone = new Minnestrone();
    }
    public void buildPastaFazul() {
        soupBuffet.pastaFazul = new PastaFazul();
    }
    public void buildTofuSoup() {
        soupBuffet.tofuSoup = new TofuSoup();
    }
    public void buildVegetableSoup() {
        soupBuffet.vegetableSoup = new VegetableSoup();
    }
}
