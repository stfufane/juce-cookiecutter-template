import re
import sys

def is_alphanumeric(string: str):
    return bool(re.match('^[a-zA-Z0-9_ ]*$', string))

project_name = '{{ cookiecutter.project_name }}'
author = '{{ cookiecutter.author }}'

if not is_alphanumeric(project_name):
    print(f'ERROR: {project_name} is not a valid project name. Only alphanumeric characters are allowed.')
    sys.exit(1)

if not is_alphanumeric(author):
    print(f'ERROR: {author} is not a valid author name. Only alphanumeric characters are allowed.')
    sys.exit(1)