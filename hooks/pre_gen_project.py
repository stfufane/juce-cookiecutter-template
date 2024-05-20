import re
import sys

def is_alphanumeric(string: str):
    return bool(re.match('^[a-zA-Z0-9_ ]*$', string))

project_name = '{{ cookiecutter.project_name }}'
manufacturer_code = '{{ cookiecutter.manufacturer_code }}'
plugin_code = '{{ cookiecutter.plugin_code }}'

if not is_alphanumeric(project_name):
    print(f'ERROR: {project_name} is not a valid project name. Only alphanumeric characters are allowed.')
    sys.exit(1)

if not is_alphanumeric(manufacturer_code) and len(manufacturer_code) != 4:
    print(f'ERROR: {manufacturer_code} is not a valid manufacturer code. Only alphanumeric characters are allowed and must be 4 characters long.')
    sys.exit(1)

if not is_alphanumeric(plugin_code) and len(plugin_code) != 4:
    print(f'ERROR: {plugin_code} is not a valid plugin code. Only alphanumeric characters are allowed and must be 4 characters long.')
    sys.exit(1)
