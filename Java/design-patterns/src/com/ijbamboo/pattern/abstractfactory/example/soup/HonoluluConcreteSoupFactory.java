package com.ijbamboo.pattern.abstractfactory.example.soup;

import com.ijbamboo.pattern.soup.ClamChowder;
import com.ijbamboo.pattern.soup.FishChowder;
import com.ijbamboo.pattern.soup.HonoluluClamChowder;
import com.ijbamboo.pattern.soup.HonoluluFishChowder;

/**
 * 檀香山 混凝土汤锅厂
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午1:38:02
 */
public class HonoluluConcreteSoupFactory extends AbstractSoupFactory{
	public HonoluluConcreteSoupFactory() {
        factoryLocation = "Honolulu";
    }
    public ClamChowder makeClamChowder() {
       return new HonoluluClamChowder();
    }
    public FishChowder makeFishChowder() {
       return new HonoluluFishChowder();
    }
}
