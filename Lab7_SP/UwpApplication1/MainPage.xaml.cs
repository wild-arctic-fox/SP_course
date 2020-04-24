using System;
using System.Collections.Generic;
using System.Globalization;
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

namespace UwpApplication1
{
    public sealed partial class MainPage : Page
    {
        private string action;

        public MainPage()
        {
            this.InitializeComponent();
        }

        private double first_operand()
        {
            try
            {
                double f = Convert.ToDouble(operand1.Text);
                return f;
            }catch (Exception e){
                action = "";
                return 0;
            }
        }

        private double second_operand()
        {
            try
            {
                double f = Convert.ToDouble(operand2.Text);
                return f;
            }catch (Exception e){
                action = "";
                return 0;
            }
        }

        private void calculate_click(object sender, RoutedEventArgs e)
        {
            string act = action;
            switch (act)
            {
                case "*":
                    res.Text = (Math.Round(first_operand() * second_operand(), 3)).ToString();
                    break;
                case "+":
                    res.Text = (Math.Round(first_operand() + second_operand(), 3)).ToString();
                    break;
                case "/":
                    res.Text = (Math.Round(first_operand() / second_operand(), 3)).ToString();
                    break;
                case "-":
                    res.Text = (Math.Round(first_operand() - second_operand(), 3)).ToString();
                    break;
                case "cos":
                    res.Text = (Math.Round(Math.Cos(first_operand()), 3)).ToString();
                    break;
                case "sin":
                    res.Text = (Math.Round(Math.Sin(first_operand()), 3)).ToString();
                    break;
                case "tan":
                    res.Text = (Math.Round(Math.Tan(first_operand()), 3)).ToString();
                    break;
                case "ctan":
                    res.Text = (Math.Round(Math.Atan(first_operand()), 3)).ToString();
                    break;
                case "^":
                    res.Text = Math.Round(Math.Pow(first_operand(), second_operand()), 3).ToString();
                    break;
                case "sqrt":
                    res.Text = Math.Round(Math.Sqrt(first_operand()), 3).ToString();
                    break;
                case "log":
                    res.Text = Math.Round(Math.Log(first_operand(), second_operand()), 3).ToString();
                    break;
                default:
                    res.Text = "Input error";
                    break;
            }
        }

        private void choose_operation(object sender, RoutedEventArgs e)
        {
            try{
                RadioButton rb = sender as RadioButton;
                action = (string) rb.Content;
            }catch (Exception er){
                action = "";
            }
        }

        private void about_click(object sender, RoutedEventArgs e)
        {
            about_me.Visibility = Visibility.Visible;
            Block.Visibility = Visibility.Collapsed;
            operand1.Visibility = Visibility.Collapsed;
            operand2.Visibility = Visibility.Collapsed;
            op4.Visibility = Visibility.Collapsed;
            op3.Visibility = Visibility.Collapsed;
            op2.Visibility = Visibility.Collapsed;
            op1.Visibility = Visibility.Collapsed;
            Button.Visibility = Visibility.Collapsed;
            TextBlock1.Visibility = Visibility.Collapsed;
            TextBlock2.Visibility = Visibility.Collapsed;
            res.Visibility = Visibility.Collapsed;
        }

        private void arifm_click(object sender, RoutedEventArgs e)
        {
            op1.Content = "+";
            op2.Content = "-";
            op3.Content = "/";
            op4.Visibility = Visibility.Visible;
            op4.Content = "*";
        }

        private void trigonom_click(object sender, RoutedEventArgs e)
        {
            op1.Content = "sin";
            op2.Content = "cos";
            op3.Content = "tan";
            op4.Visibility = Visibility.Visible;
            op4.Content = "ctan";
        }

        private void algebr_click(object sender, RoutedEventArgs e)
        {
            op1.Content = "^";
            op2.Content = "sqrt";
            op3.Content = "log";
            op4.Visibility = Visibility.Collapsed;
        }
    }
}