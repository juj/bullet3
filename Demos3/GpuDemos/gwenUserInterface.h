#ifndef _GWEN_USER_INTERFACE_H
#define _GWEN_USER_INTERFACE_H

struct GwenInternalData;

typedef void (*b3ComboBoxCallback) (int combobox, const char* item);
typedef void (*b3ToggleButtonCallback)(int button, int state);



class GwenUserInterface
{
	GwenInternalData*	m_data;

	public:
		
		GwenUserInterface();
		
		virtual ~GwenUserInterface();
		
		void	init(int width, int height,struct sth_stash* stash,float retinaScale);
		
		void	draw(int width, int height);

		void	resize(int width, int height);
				
		bool	mouseMoveCallback( float x, float y);
		bool	mouseButtonCallback(int button, int state, float x, float y);
		bool	keyboardCallback(int key, int state);


		void	setToggleButtonCallback(b3ToggleButtonCallback callback);
		b3ToggleButtonCallback getToggleButtonCallback();

		void	registerToggleButton(int buttonId, const char* name);

		void	setComboBoxCallback(b3ComboBoxCallback callback);
		b3ComboBoxCallback getComboBoxCallback();
		void	registerComboBox(int buttonId, int numItems, const char** items, int startItem = 0);
		
		void	setStatusBarMessage(const char* message, bool isLeft=true);

		GwenInternalData* getInternalData()
		{
			return m_data;
		}

};

#endif //_GWEN_USER_INTERFACE_H

