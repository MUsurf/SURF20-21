from setuptools import find_packages, setup
setup(
    name = 'SURFpythonLib',
    packages = find_packages(include=['SURFpythonLib']), #this is where I add packages, number package?
    version ='0.1.0',
    description = 'My first Python library',
    author = 'SURF',
    license = 'MIT',
)
