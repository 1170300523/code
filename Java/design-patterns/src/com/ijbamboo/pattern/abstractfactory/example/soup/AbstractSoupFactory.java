package com.ijbamboo.pattern.abstractfactory.example.soup;

import com.ijbamboo.pattern.soup.ChickenSoup;
import com.ijbamboo.pattern.soup.ClamChowder;
import com.ijbamboo.pattern.soup.FishChowder;
import com.ijbamboo.pattern.soup.Minnestrone;
import com.ijbamboo.pattern.soup.PastaFazul;
import com.ijbamboo.pattern.soup.TofuSoup;
import com.ijbamboo.pattern.soup.VegetableSoup;

/**
 * 抽象的汤工厂
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午1:27:53
 */
public abstract class AbstractSoupFactory {
	String factoryLocation;

	public String getFactoryLocation() {
		return factoryLocation;
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
}
