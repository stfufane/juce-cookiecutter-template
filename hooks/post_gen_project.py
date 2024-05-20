import os
import shutil

# Remove the file that we don't need
{% if not cookiecutter.include_ear_protection %}
os.remove('src/processor/Utils.h')
{% endif %}

{% if not cookiecutter.include_gui_example %}
shutil.rmtree('src/gui')
{% endif %}
