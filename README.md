<div align="left">
<h1>Quick Menu Minus</h1> 

<p>Quick Menu Minus is a fork of <a href="https://github.com/PsArchive/QuickMenuPlus"> QuickMenuPlus </a> that adds custom enhancements and features to the Quick Menu on the PlayStation Vita and PlayStation TV.</p>

<h3>Key differences from QuickMenuPlus: </h3>
<ul>
  <li><b>No PlayStation Plus logos/icons:</b> Completely removed PS Plus visual branding for a cleaner look.</li>
  <li>Updated Background Logic (<code>bgstyle.txt</code>):</li> <br>
    <ul>
      <li><code>0</code> = Transparent </li>
      <li><code>1</code> = Gray </li>
      <li><code>2</code> = Black</li> <br>
    </ul>
  <li><b>Disabled Gradient by Default</b> (<code>bggradient.txt</code>)<b>:</b> The background gradient effect is now disabled by default. To enable it, create the file and set its value to <code>1</code>.</li>
</ul>


<p align="center">
  <img src="./imgs/overall-preview.png" alt="Overall Preview" width="600"/>
</p>

<h2>Installation</h2>

<p>Supported firmware versions:</p>
<ul>
  <li>Retail 3.60-3.73</li>
  <li>Testkit 3.60, 3.65</li>
  <li>Devkit 3.60</li>
</ul>

<p>Write the file path in the <code>*main</code> section of your taiHEN config.</p>

<pre><code class="language-bash">*main                        
ur0:/tai/quickmenuminus.suprx
</code></pre>
<br>

<h2>Configuration</h2>

<p>Put files in the directory <code>ur0:/data/quickmenuminus</code> to configure Quick Menu Minus.</p>
<ul>
  
<li> <code>pushtime.txt</code> sets the Quick Menu PS button push time. Put in the file the desired push time in microseconds. For example, put <code>250000</code> for 250 milliseconds. If the file does not exist, the default time is 500 milliseconds.</li>

<li> <code>standbyisrestart.txt</code> sets the standby button to function as a restart button. Put in the file <code>1</code> to enable, or <code>0</code> to disable. If the file does not exist, the default is enabled on the Vita, and disabled on the PSTV. When this setting is disabled, hold the "Power Off・Restart" button to restart, and press to power off.</li>

  <br><p align="center">
    <img src="./imgs/power-preview.png" alt="Power Preview" width="500"/>
  </p><br>

<li> <code>bgstyle.txt</code> sets the background style. Put in the file <code>0</code> for transparent, <code>1</code> for gray, and <code>2</code> for black. If the file does not exist, the default is transparent (<code>0</code>). Black can reduce power consumption for OLED screens.</li><br>

  <p align="center">
  	<img src="./imgs/bg-preview-translucent.png" alt="Background Style Preview Translucent" width="700"/> <br>
    <img src="./imgs/bg-preview-og.png" alt="Background Style Preview Original" width="700"/> <br>
    <img src="./imgs/bg-preview-black.png" alt="Background Style Preview Black" width="700"/><br>
  </p>

<li> <code>bggradient.txt</code> sets the background gradient effect. Put in the file <code>0</code> to disable, and <code>1</code> to enable. If the file does not exist, the default is disabled (<code>0</code>). </li>
</ul>
<br>

<h2>Building</h2>

<p>Tested with VitaSDK 2026.08 (GCC 15.2.0) on Linux.</p>

<h3>1. Install VitaSDK</h3>

<p>Follow the instructions at <a href="https://vitasdk.org">vitasdk.org</a>, then make sure the environment is set:</p>

<pre><code class="language-bash">export VITASDK=$HOME/vitasdk
export PATH=$VITASDK/bin:$PATH
</code></pre>

<p>Install the taiHEN package:</p>

<pre><code class="language-bash">vdpm install taihen
</code></pre>

<h3>2. Install the PAF headers</h3>

<p>The module uses the <a href="https://github.com/VitaArchive/ScePaf-RE/tree/c-compat">ScePaf-RE (<code>c-compat</code> branch)</a> headers. Copy them into the SDK:</p>

<pre><code class="language-bash">git clone -b c-compat https://github.com/VitaArchive/ScePaf-RE.git
cp -r ScePaf-RE/include/* $VITASDK/arm-vita-eabi/include/
</code></pre>

<p>Then fix the include in <code>paf/std/wchar.h</code>, which points outside the SDK include path:</p>

<pre><code class="language-bash">sed -i 's|#include &lt;../../wchar.h&gt;|#include &lt;stdarg.h&gt;\n#include &lt;stddef.h&gt;\n#include &lt;wchar.h&gt;|' \
  $VITASDK/arm-vita-eabi/include/paf/std/wchar.h
</code></pre>

<h3>3. Build</h3>

<pre><code class="language-bash">git clone https://github.com/arcomipiaceilseno/QuickMenuMinus.git
cd QuickMenuMinus
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
</code></pre>

<p>The module is created at <code>build/quickmenuminus.suprx</code>.</p>

<h3>Notes</h3>
<ul>
  <li><code>vita_missing.h</code> and <code>vita_missing.c</code> provide prototypes and import stubs for system functions that are not in the public VitaSDK headers or stub libraries (<code>sceShellUtilRequestColdReset</code>, <code>sceRegMgrUtilityGetInt</code>, <code>sceAVConfigGetVolCtrlEnable</code>, <code>sceAVConfigWriteRegSystemVol</code>, <code>vshPowerSetPsButtonPushTime</code>, <code>sceClibStrtoll</code> and some PAF functions). They were derived from the imports of a working build and are not official: if VitaSDK declares them in the future, these files can be removed.</li>
  <li>The PAF functions are linked from <code>ScePaf_stub_weak</code>, plus the stubs defined in <code>vita_missing.c</code>.</li>
  <li><code>-fshort-wchar</code> is required, because <code>wchar_t</code> is 16-bit on the Vita.</li>
</ul>

<h2>Contributing</h2>

<p>Feel free to open issues and pull requests for the project!</p>

<h2>Credits</h2>
<ul>
<li>Princess-of-Sleeping: Tip for SceShellUtil, ScePaf</li>
<li>Team CBPS: For the original project</li> 
</ul>


<h2>See also</h2>
    <a href="https://github.com/PsArchive/QuickMenuPlus">Original repository</a>
</div>
