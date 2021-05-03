#from . import calculadora
from setuptools import setup

setup(
    name="Calculadora de Conjuntos",
    autor="Joseph Hynimoto Aguilar Lopez",
    packages=["calculadora","calculadora/operations"],
    entry_points={
        "console_scripts": ["conjuntos=calculadora.calcu:main"]
    },
    install_requires=[
        "numpy",
        "datetime",
        "setuptools"
    ],

    include_package_data = True,
    python_requires=">=3.7",
    classifiers=[
        "Development Status :: Alpha",
        "Environment :: Console",
        "Programming Language :: Python",
        "Programming Language :: Python :: 3",
        "Programming Language :: Python :: 3.5",
        "Programming Language :: Python :: 3.6",
        "Programming Language :: Python :: 3.7",
        "Programming Language :: Python :: 3.8",
    ],
)
