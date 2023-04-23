#!/bin/env python3

import jinja2
import json

env = jinja2.Environment(
    loader=jinja2.FileSystemLoader(searchpath="./")
)
msg_template = env.get_template("messages.jinja2")

schema = dict()
with open("schema.json","r") as jsonfile:
    schema = json.load(jsonfile)

rendered_header = msg_template.render(schema)
with open("messages.hpp","w") as outfile:
    print(rendered_header,file=outfile)