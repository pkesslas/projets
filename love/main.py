import kivy
kivy.require('1.8.0')

from kivy.app import App
from kivy.uix.gridlayout import GridLayout
from kivy.uix.label import Label
from kivy.uix.button import Button
from kivy.uix.textinput import TextInput
from kivy.config import Config
from kivy.properties import ObjectProperty, StringProperty

Config.set('graphics', 'width', '600')
Config.set('graphics', 'height', '100')


class NameScreen(GridLayout):

	def __init__(self, **kwargs):
		super(NameScreen, self).__init__(**kwargs)
		self.rows = 2

	result = StringProperty("0%")

	def Love(self, name1, name2):

		if name1.lower() == "caroline" and name2.lower() == "pierre-elie"\
			or name1.lower() == "pierre-elie" and name2.lower() == "caroline":
			self.result = "100%"
		else:
			res = sum(map(ord, name1)) + sum(map(ord, name2))
			self.result = str(res % 100) + "%"

	def callback(self, evt=None):
		self.Love(self.ids.name1.text, self.ids.name2.text)

class LoveApp(App):

	def build(self):
		 return NameScreen()

if __name__ == '__main__':
	LoveApp().run()
