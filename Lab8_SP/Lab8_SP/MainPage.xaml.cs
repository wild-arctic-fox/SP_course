using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.Storage;
using Windows.Storage.Pickers;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;


namespace Lab8_SP
{
    public sealed partial class MainPage : Page
    {
        ObservableCollection<DirectoryData> dirs = new ObservableCollection<DirectoryData>();
        StorageFolder storage;
        List<StorageFolder> prevFolders = new List<StorageFolder>();
        StorageFolder prevFolder = null;
        StorageFolder currentFolder = Windows.ApplicationModel.Package.Current.InstalledLocation;
        string parent;

        public MainPage()
        {
            this.InitializeComponent();
            listView.ItemsSource = dirs;
        }

        private async void open_folder(object sender, RoutedEventArgs e)
        {
            prevFolders.Clear();
            FolderPicker fp = new FolderPicker();
            fp.ViewMode = PickerViewMode.Thumbnail;
            fp.SuggestedStartLocation = PickerLocationId.Desktop;
            fp.FileTypeFilter.Add("*");
            storage = await fp.PickSingleFolderAsync();
            parent = storage.Name;
            get_directories(storage);
        }

        private async void get_directories(StorageFolder sf1)
        {
            dirs.Clear();
            
            IReadOnlyList<StorageFile> files = await sf1.GetFilesAsync();
            IReadOnlyList<StorageFolder> folders = await sf1.GetFoldersAsync();

            dirs.Add(new DirectoryData(){
                DirName = "DirName",
                DirDate = "DirDate Created",
                DirType = "DirType",
                DirSize = "DirSize"
            });
            
            dirs.Add(new DirectoryData(){
                DirName = "..",
                DirDate = "",
                DirType = "",
                DirSize = ""
            });
           
            foreach (StorageFolder folder in folders){
                dirs.Add(new DirectoryData(){
                    DirName = folder.Name,
                    DirDate = folder.DateCreated.UtcDateTime.ToString(@"MM\/dd\/yyyy HH:mm"),
                    DirType = "Folder",
                    DirSize = ""
                });
            }
           
            foreach (StorageFile file in files){
                var props = await file.GetBasicPropertiesAsync();
                dirs.Add(new DirectoryData(){
                    DirName = file.Name, DirDate = file.DateCreated.UtcDateTime.ToString(@"MM\/dd\/yyyy HH:mm"),
                    DirType = "File", DirSize = count_size(props.Size)
                });
            }
        }

        private string count_size(ulong file_size)
        {
            ulong finalSize = file_size;
            if (finalSize >= 1024 * 1024 * 1024){
                finalSize /= 1024 * 1024;
                return finalSize + " MB";
            }
            if (finalSize >= 1024){
                finalSize /= 1024;
                return finalSize + " KB";
            }
            return finalSize + " B";
        }

        private async void folder_click(object sender, DoubleTappedRoutedEventArgs e)
        {
            DirectoryData mf = (DirectoryData) listView.SelectedItem;

            if (mf.DirName == ".."){
                if (prevFolders.Count != 0){
                    storage = prevFolders[prevFolders.Count - 1];
                    get_directories(storage);
                    prevFolders.RemoveAt(prevFolders.Count - 1);
                }
            }
            else if (mf.DirType == "Folder"){
                prevFolders.Add(storage);
                storage = await storage.GetFolderAsync(mf.DirName);
                get_directories(storage);
            }
        }

        private void context_menu(object sender, RightTappedRoutedEventArgs e)
        {
            FrameworkElement senderElement = sender as FrameworkElement;
            FlyoutBase flyoutBase = FlyoutBase.GetAttachedFlyout(senderElement);
            flyoutBase.ShowAt(senderElement);
        }

        private async void delete_click(object sender, RoutedEventArgs e)
        {
            try{
                DirectoryData datacontext = (DirectoryData) (e.OriginalSource as FrameworkElement).DataContext;
                if (datacontext.DirType == "Folder"){
                    StorageFolder storfile = await storage.GetFolderAsync(datacontext.DirName);
                    await storfile.DeleteAsync();
                    get_directories(storage);
                    error.Text = "";
                }
            }catch (Exception exception){
                error.Text = "Can not delete folder!";
            }
        }
        
        private async void create_folder(object sender, RoutedEventArgs e)
        {
            try{
                StorageFolder localFolder = currentFolder;
                string desiredName = folderName.Text;
                await localFolder.CreateFolderAsync(desiredName);
                get_directories(storage);
                error.Text = "";
            }catch(Exception exception){
                error.Text = "Can not add folder!";
            }
        }
    }

    internal class DirectoryData
    {
        public string DirName { get; set; }
        public string DirSize { get; set; }
        public string DirDate { get; set; }
        public string DirType { get; set; }
    }
}