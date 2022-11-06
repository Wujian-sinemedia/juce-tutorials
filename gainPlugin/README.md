# Gain Slider Plugin

Humans perceive volume logarithmically,


$$X_{dB} = 20log(x)$$

where X<sub>dB</sub> denotes loudness in decibals and x denotes position

The slider value represents L.
solving for x, we get

$$x = 10^{X_{dB}/20}$$

```
rawVolume = pow(10, sliderValue / 20)
```

<hr>
<h3>References</h3>
<a href="http://hyperphysics.phy-astr.gsu.edu/hbase/Sound/db.html">Loudness</a><br>
<a href="https://www.cuemath.com/algebra/logarithms/">Logarithm</a>