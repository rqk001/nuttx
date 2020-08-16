# Configuration file for the Sphinx documentation builder.
#
# This file only contains a selection of the most common options. For a full
# list see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Path setup --------------------------------------------------------------

# If extensions (or modules to document with autodoc) are in another directory,
# add these directories to sys.path here. If the directory is relative to the
# documentation root, use os.path.abspath to make it absolute, like shown here.
#
# import os
# import sys
# sys.path.insert(0, os.path.abspath('.'))


# -- Project information -----------------------------------------------------

project = 'NuttX'
copyright = '2020, The Apache Software Foundation'
author = 'NuttX community'
version = release = 'latest'


# -- General configuration ---------------------------------------------------

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
# ones.
extensions = [
    "sphinx_rtd_theme",
    "recommonmark",
    'sphinx.ext.autosectionlabel',
    'sphinx.ext.todo'
]

todo_include_todos = True

autosectionlabel_prefix_document = True

# do not set Python as primary domain for code blocks
highlight_language = "none"
primary_domain = None

# Add any paths that contain templates here, relative to this directory.
templates_path = ['_templates']

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This pattern also affects html_static_path and html_extra_path.
exclude_patterns = ['_build', 'Thumbs.db', '.DS_Store']

# list of documentation versions to offer (besides latest)

html_context = dict()
html_context['nuttx_versions'] = ['latest']

# TODO: append other options using releases detected from git (or maybe just
# a few hand-selected ones, or maybe just a "stable" option)

# -- Options for HTML output -------------------------------------------------

# The theme to use for HTML and HTML Help pages.  See the documentation for
# a list of builtin themes.
#
html_theme = 'sphinx_rtd_theme'

html_show_sphinx = False

html_theme_options = {
    'prev_next_buttons_location': None
}

# Add any paths that contain custom static files (such as style sheets) here,
# relative to this directory. They are copied after the builtin static files,
# so a file named "default.css" will overwrite the builtin "default.css".
html_static_path = ['_static']

html_css_files = [
    'custom.css'
]

html_show_license = True

html_logo = '_static/NuttX.png'
html_favicon = '_static/favicon.ico'

today_fmt = '%d %B %y at %H:%M'

c_id_attributes = [
  'FAR',
  'CODE',
  'noreturn_function'
]
