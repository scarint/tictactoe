using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

namespace UWPTicTacToe
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        TextBlock selected;
        Thickness show = new Thickness(5, 5, 5, 5);
        Thickness hide = new Thickness(0, 0, 0, 0);

        public MainPage()
        {
            this.InitializeComponent();
        }

        private void BoxSelectionChanged(object sender, PointerRoutedEventArgs e)
        {
            // Assign sender to the box that was clicked
            TextBlock clicked = (TextBlock)sender;

            // Check border
            if (Box00Border.BorderThickness == hide)                        // If selection border is hidden
            {
                Box00Border.BorderThickness = show;                         // Show it and set our selected values
                selected = Box00;
            }
            else                                                            // Otherwise, it's already visible
            {
                Box00Border.BorderThickness = hide;                         // So "delete" it, and
                Box00.Text = "X";                                           // set the TextBlock,
                selected = null;                                            // and  clear selected
            }
        }
    }
}
