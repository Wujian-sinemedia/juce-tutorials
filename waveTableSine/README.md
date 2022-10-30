# Wave Table Synthesis

To create a wave table we use an array of size 1024. the array has 1024 instances of samples for a single cycle.<br>

To calculate position of wave for an instance, we have<br>

$$y = sin(2πx/λ)$$

We can take our wave table size instead of wavelength(λ) and each instance instead of x.

```
Repeat for i from 0 to wavetablesize - 1
    wavetable[i] = 2πi * wavetablesize
```

We know

$$ω = 2πf$$

If we take wavetablesize instead of of 2π, we get phase covered in 1 s. Dividing it by sample rate gives the phase covered in between 2 consecutive instances.

```
increment = f * wavetablesize / samplerate
```

<hr>
<h3>References</h3>
<a href="https://byjus.com/jee/wave-equation/">Wave equations</a><br>
<a href="https://www.izotope.com/en/learn/digital-audio-basics-sample-rate-and-bit-depth.html">Sample rate</a>